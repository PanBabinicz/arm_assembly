        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_rcc.inc"
        .include "stm32f446re_gpio.inc"
        .include "stm32f446re_systick.inc"

        stk_load_reload_value = 0x00100000

        .data
        .balign 4
        .type blink_pattern, %object
blink_pattern:
        .byte 0x01
        .byte 0x02
        .byte 0x03
        .byte 0x04
        .byte 0x03
        .byte 0x02
        .byte 0x01
blink_pattern_end:

        .data
        .balign 4
blink_pattern_current_pattern:
        .byte 0x00

        .data
        .balign 4
blink_pattern_current_index:
        .byte 0x00

        .text
        .global _reset_handler
        .balign 4
        .type _reset_handler, %function
_reset_handler:
        bl _rcc_setup
        bl _gpio_setup
        bl _stk_setup
        bl _main
        b .                 @ Never return.

        .text
        .global _systick_handler
        .balign 4
        .type _systick_handler, %function
_systick_handler:
        push { lr }
        ldr r0, =blink_pattern_current_pattern
        ldr r1, =blink_pattern_current_index
        ldr r2, [r0]
        ldr r3, [r1]
        subs r2, #0x01
        bne skip
        ldr r2, [r0], #4
        str r2, [r0]
        str r0, [r1]
        ldr r0, =gpioa_base
        mov r1, #gpiox_bsrr_bs5
        mov r2, #gpiox_bsrr_br5
        bl _blink
skip:
        pop { lr }
        bx lr

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
        mov r1, #gpiox_bsrr_bs5
        str r1, [r0, #gpiox_bsrr_offset]
        bx lr

        .text
        .balign 4
        .type _stk_setup, %function
_stk_setup:
        ldr r0, =stk_base
        mov r1, #(stk_ctrl_enable | stk_ctrl_tickint | stk_ctrl_clksource)
        mov r2, #stk_load_reload_value
        str r2, [r0, stk_load_offset]
        str r1, [r0, stk_ctrl_offset]
        bx lr

        .text
        .balign 4
        .type _blink, %function
_blink:
        ldr r3, [r0, #gpiox_odr_offset]
        tst r3, #gpiox_odr_odr5
        bne off
        str r1, [r0, #gpiox_bsrr_offset]
        b blink_end
off:
        str r2, [r0, #gpiox_bsrr_offset]
blink_end:
        bx lr

        .text
        .balign 4
        .type _main, %function
_main:
        push { lr }
        ldr r0, =blink_pattern
        ldr r1, [r0], #4
        ldr r2, =blink_pattern_current_pattern
        str r1, [r2]
        ldr r2, =blink_pattern_current_index
        str r0, [r2]
1:
        wfi                 @ SysTick handler will make the work.
        b 1b
        pop { lr }          @ Should never go here.
        bx lr

        .end
