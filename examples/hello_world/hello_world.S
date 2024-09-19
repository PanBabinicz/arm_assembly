        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_rcc.inc"
        .include "stm32f446re_gpio.inc"
        .include "stm32f446re_usart.inc"

        .global _usart_init
        .global _usart_send_data

        .section .rodata
        .balign 4
        .type hello_world_message, %object
hello_world_message:
        .asciz "Hello, World!"

        .text
        .balign 4
        .global _reset_handler
        .type _reset_handler, %function
_reset_handler:
        bl _rcc_setup
        bl _gpio_setup
        ldr r0, =usart2_base
        bl _usart_init
        bl _main
        b .                     @ Never return.

        .text
        .balign 4
        .type _rcc_setup, %function
_rcc_setup:
        ldr r0, =rcc_base
        ldr r1, [r0, #rcc_ahb1enr_offset]
        orr r1, #rcc_ahb1enr_gpioaen
        str r1, [r0, #rcc_ahb1enr_offset]
        ldr r1, [r0, #rcc_apb1enr_offset]
        orr r1, #rcc_apb1enr_usart2en
        str r1, [r0, #rcc_apb1enr_offset]
        bx lr

        .text
        .balign 4
        .type _gpio_setup, %function
_gpio_setup:
        ldr r0, =gpioa_base
        ldr r1, [r0, #gpiox_moder_offset]
        orr r1, #(gpiox_moder_moder2_bit1 | gpiox_moder_moder3_bit1)
        str r1, [r0, #gpiox_moder_offset]
        ldr r1, [r0, #gpiox_afrl_offset]
        orr r1, #(gpiox_afrl_afrl2_bit0 | gpiox_afrl_afrl2_bit1 | gpiox_afrl_afrl2_bit2)
        orr r1, #(gpiox_afrl_afrl3_bit0 | gpiox_afrl_afrl3_bit1 | gpiox_afrl_afrl3_bit2)
        str r1, [r0, #gpiox_afrl_offset]
        bx lr

        .text
        .balign 4
        .type _main, %function
_main:
        push { lr }             @ Push only 4 bytes.
        sub sp, sp, #4          @ Adjust to maintain 8-byte alignment.
        ldr r0, =usart2_base
        ldr r1, =hello_world_message
        bl _usart_send_data
1:
        wfi
        b 1b
        add sp, sp, #4          @ Restore stack pointer before returning.
        pop { lr }              @ Should never go here.
        bx lr

        .end
