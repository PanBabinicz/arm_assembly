        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_usart.inc"

        .section .rodata
        .balign 4
        .type hello_world_message, %object
hello_world_message:
        .asciz "Hello, World!"

        .text
        .balign 4
        .type _usart_enable, %function
        @ Argument in r0: usart base address
_usart_enable:
        ldr r1, [r0, #usart_cr1_offset]
        orr r1, #usart_cr1_ue
        str r1, [r0, #usart_cr1_offset]
        bx lr

        .text
        .balign 4
        .type _usart_set_m_bit, %function
        @ Argument in r0: usart base address
        @ Argument in r1: m bit value
_usart_set_m_bit:
        ldr r2, [r0, #usart_cr1_offset]
        orr r2, r1
        str r2, [r0, #usart_cr1_offset]
        bx lr

        .text
        .balign 4
        .type _usart_set_stop_bits, %function
        @ Argument in r0: usart base address
        @ Argument in r1: set bits value
_usart_set_stop_bits:
        ldr r2, [r0, #usart_cr2_offset]
        orr r2, r1
        str r2, [r0, #usart_cr2_offset]
        bx lr

        .text
        .balign 4
        .type _usart_set_baud_rate, %function
        @ Argument in r0: usart base address
        @ Argument in r1: fraction value
        @ Argument in r2: mantissa value
        @ The reset value of sysclk is 96MHz
        @ It is calculated like this, values are in RCC_PLLCFGR register:
        @ 1. Check which oscilator is used (on reset it is HSI which is 16MHz)
        @ 2. Divide PLL input clock by PLLM which is 16
        @ 3. The divided input clock is 1MHz, multiply it by PLLN (192)
        @ 4. The VCO is now 192MHz, lets divide it by PLLP (which is 2)
        @ 5. The main system clock is now set to 96MHz
        @ On the clock tree you can see that APB1 gets sysclk which is
        @ main system clock
        @ The last thing is to check if there are any prescalers in
        @ RCC_CFGR register.
        @ For 9600 baudrate and 96MHz clock the mantissa has to be
        @ set to 625, it is calculated in the following way:
        @ 1. USARTDIV = fpclk1/(16*9600) = 96MHz/(16*9600) = 625
        @ NOTE: the PLL can be not turned on, so SYSCLK will be 16MHz
        @ 1. USARTDIV = 16MHz/(16*9600) = 104.1667
        @ 2. mantissa = 104 (0x68)
        @ 3. fraction = 0.1667 * 16 = 2.667 = 3 (0x03)
_usart_set_baud_rate:
        lsl r2, #usart_brr_divmantissa_position
        orr r2, r1
        str r2, [r0, #usart_brr_offset]
        bx lr

        .text
        .balign 4
        .type _usart_set_idle_frame, %function
_usart_set_idle_frame:
        ldr r1, [r0, #usart_cr1_offset]
        orr r1, #usart_cr1_te
        str r1, [r0, #usart_cr1_offset]
        bx lr

        .text
        .balign 4
        .type _usart_send_data, %function
        @ Argument in r0: usart base address
        @ Argument in r1: address of the message
_usart_send_data:
1:
        ldrb r2, [r1], #1
        cmp r2, #0x00
        beq usart_send_end
        strb r2, [r0, #usart_dr_offset]
2:
        ldr r3, [r0, #usart_sr_offset]
        tst r3, #usart_sr_txe
        beq 2b
        b 1b
usart_send_end:
        ldr r3, [r0, #usart_sr_offset]
        tst r3, #usart_sr_tc
        beq usart_send_end
        bx lr

        .text
        .balign 4
        .global _usart_init
        .type _usart_init, %function
        @ Argument in r0: usart base address
_usart_init:
        push { lr }
        bl _usart_enable        @ Argument in r0 is usart base address.
        mov r1, #0x00
        bl _usart_set_m_bit
        mov r1, #0x00
        bl _usart_set_stop_bits
        mov r1, #0x03
        mov r2, #0x68
        bl _usart_set_baud_rate
        bl _usart_set_idle_frame
        pop { lr }
        bx lr

        .end
