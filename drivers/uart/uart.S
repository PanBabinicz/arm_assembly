        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_usart.inc"

        .text
        .balign 4
        .global _reset_handler
        .type _reset_handler, %function
_reset_handler:
        ldr r0, =usart2_base
        bl _usart_init
        b .

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
_usart_set_baud_rate:
        lsl r2, #usart_brr_divmantissa_position
        orr r2, r1
        str r2, [r0, #usart_brr_offset]
        bx lr

        .text
        .balign 4
        .global _usart_init
        .type _usart_init, %function
        @ Argument in r0: usart base address
_usart_init:
        bl _usart_enable        @ Argument in r0 is usart base address.
        mov r1, #0x00
        bl _usart_set_m_bit
        mov r1, #0x00
        bl _usart_set_stop_bits
        mov r1, #0x00
        mov r2, #0x0271
        bl _usart_set_baud_rate
        bx lr

        .end
