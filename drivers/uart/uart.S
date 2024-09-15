        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_usart.inc"

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
_usart_set_baud_rate:

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
        bl _usart_set_baud_rate

        .end
