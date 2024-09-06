        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_rcc.inc"
        .include "stm32f446re_gpio.inc"

        delay_value = 0x00100000

        .text
        .balign 4
        .global _reset_handler
        .type _reset_handler, %function
_reset_handler:
        bl _rcc_setup
        bl _gpio_setup
        bl _main
        b .                 @ Never return.

        .text
        .balign 4
        .type _rcc_setup, %function
_rcc_setup:
        ldr r0, =rcc_base
        ldr r1, [r0, #rcc_ahb1enr_offset]
        orr r1, #rcc_ahb1enr_gpioaen
        str r1, [r0, #rcc_ahb1enr_offset]
        bx lr

        .text
        .balign 4
        .type _gpio_setup, %function
_gpio_setup:
        ldr r0, =gpioa_base
        ldr r1, [r0, #gpiox_moder_offset]
        orr r1, #gpiox_moder_moder5_bit0
        str r1, [r0, #gpiox_moder_offset]
        bx lr

        .text
        .balign 4
        .type _led_turn_on, %function
_led_turn_on:
        ldr r0, =gpioa_base
        ldr r1, =gpiox_bsrr_bs5
        str r1, [r0, #gpiox_bsrr_offset]
        bx lr

        .text
        .balign 4
        .type _led_turn_off, %function
_led_turn_off:
        ldr r0, =gpioa_base
        ldr r1, =gpiox_bsrr_br5
        str r1, [r0, #gpiox_bsrr_offset]
        bx lr

        .text
        .balign 4
        .type _delay, %function
_delay:
1:
        subs r0, #1
        bne 1b
        bx lr

        .text
        .balign 4
        .type _main, %function
_main:
        push { lr }
1:
        bl _led_turn_on
        ldr r0, =delay_value
        bl _delay
        bl _led_turn_off
        ldr r0, =delay_value
        bl _delay
        b 1b
        pop { lr }          @ Should never go here.
        bx lr

        .end
