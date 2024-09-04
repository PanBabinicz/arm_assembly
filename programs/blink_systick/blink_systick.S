        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_rcc.inc"
        .include "stm32f446re_gpio.inc"
        .include "stm32f446re_systick.inc"

        stk_load_reload_value = 0x00100000

        .text
        .global _reset_handler
        .type _reset_handler, %function
_reset_handler:
        bl _rcc_setup
        bl _gpio_setup
        bl _stk_setup
        bl _main
        b .                 @ Never return.

        .text
        .type _rcc_setup, %function
_rcc_setup:
        ldr r0, =rcc_base
        ldr r1, [r0, #rcc_ahb1enr_offset]
        orr r1, #rcc_ahb1enr_gpioaen
        str r1, [r0, #rcc_ahb1enr_offset]
        bx lr

        .text
        .type _gpio_setup, %function
_gpio_setup:
        ldr r0, =gpioa_base
        ldr r1, [r0, #gpiox_moder_offset]
        orr r1, #gpiox_moder_moder5_bit0
        str r1, [r0, #gpiox_moder_offset]
        bx lr

        .text
        .type _stk_setup, %function
_stk_setup:
        ldr r0, =stk_base
        mov r1, #stk_ctrl_enable
        ldr r2, =stk_load_reload_value
        mov r3, #0x00
        str r2, [r0, #stk_load_offset]
        str r3, [r0, #stk_val_offset]
        str r1, [r0, #stk_ctrl_offset]
        bx lr

        .text
        .type _toggle_led, %function
_toggle_led:
        ldr r3, [r0, #gpiox_odr_offset]
        tst r3, #gpiox_odr_odr5
        bne led_off
        str r1, [r0, #gpiox_bsrr_offset]
        b toggle_led_end
led_off:
        str r2, [r0, #gpiox_bsrr_offset]
toggle_led_end:
        bx lr

        .text
        .type _check_the_stk_flag, %function
_check_the_stk_flag:
        push { lr }
        ldr r0, =stk_base
        ldr r1, [r0, #stk_ctrl_offset]
        tst r1, #stk_ctrl_countflag
        beq check_end
        ldr r0, =gpioa_base
        mov r1, #gpiox_bsrr_bs5
        mov r2, #gpiox_bsrr_br5
        bl _toggle_led
check_end:
        pop { lr }
        bx lr

        .text
        .type _main, %function
_main:
        push { lr }
1:
        bl _check_the_stk_flag
        b 1b
        pop { lr }          @ Should never go here.
        bx lr
