        .syntax unified
        .cpu cortex-m4
        .thumb


@-----------------------------------------------------------------------------------------------@
@--------------------------------- USART registers offsets -------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ usart1_base,           (0x40011000)    @ USART1 register boundary address
        .equ usart2_base,           (0x40004400)    @ USART2 register boundary address
        .equ usart3_base,           (0x40004800)    @ USART3 register boundary address
        .equ uart4_base,            (0x40004c00)    @ UART4 register boundary address
        .equ uart5_base,            (0x40005000)    @ UART5 register boundary address
        .equ usart6_base,           (0x40011400)    @ USART6 register boundary address

        .equ usart_sr_offset,       (0x00)          @ USART status register offset
        .equ usart_dr_offset,       (0x04)          @ USART data register offset
        .equ usart_brr_offset,      (0x08)          @ USART baud rate register offset
        .equ usart_cr1_offset,      (0x0c)          @ USART control register 1 offset
        .equ usart_cr2_offset,      (0x10)          @ USART control register 2 offset
        .equ usart_cr3_offset,      (0x14)          @ USART control register 3 offset
        .equ usart_gtpr_offset,     (0x18)          @ USART guard time and prescaler register
                                                    @ offset


@-----------------------------------------------------------------------------------------------@
