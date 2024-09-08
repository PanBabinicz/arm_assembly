        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_rcc.inc"
        .include "stm32f446re_gpio.inc"

        delay_number_of_iterations = 0x00100000

        .text
        .balign 4
        .global _reset_handler
        .type _reset_handler, %function
_reset_handler:
        bl _rcc_setup
        bl _gpio_setup
        ldr r0, =gpioa_base                     @ _blink function argument 0
        ldr r1, =gpiox_bsrr_bs5                 @ _blink function argument 1
        ldr r2, =gpiox_bsrr_br5                 @ _blink function argument 2
        ldr r3, =delay_number_of_iterations     @ _blink function argument 3
        bl _blink
        b .                                     @ Never return.

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
        .type _blink, %function
_blink:
        push { r4, lr }
        mov r4, r0
blink_loop:
        str r1, [r4, #gpiox_bsrr_offset]
        mov r0, r3
        bl _blink_delay
        str r2, [r4, #gpiox_bsrr_offset]
        mov r0, r3
        bl _blink_delay
        b blink_loop

        .text
        .balign 4
        .type _blink_delay, %function
_blink_delay:
loop:
        subs r0, #1
        cmp r0, #0
        bne loop
        bx lr

        .end
