    .syntax unified
    .cpu cortex-m4
    .thumb

    .include "stm32f446re_constants.inc"

    blink_loop_size = 1000000

    .text
    .type _reset_handler, %function
    .global _reset_handler
_reset_handler:
    ldr r0, =stm32_rcc_ahb1enr_base       @ RCC enable for GPIOA.
    ldr r1, [r0]
    orr r1, #stm32_rcc_ahb1enr_gpioaen
    str r1, [r0]
    ldr r0, =stm32_gpiox_moder_base       @ Set GPIOA pin5 to output.
    ldr r1, [r0]
    orr r1, #stm32_gpiox_moder_output_5
    str r1, [r0]
    ldr r0, =stm32_gpiox_bsrr_base        @ Store the constant values for setting leds on/off.
    ldr r1, =stm32_gpiox_bsrr_bs5
    ldr r2, =stm32_gpiox_bsrr_br5
    ldr r3, =blink_loop_size
blink_loop:
    str r1, [r0]                          @ Set GPIOA pin5 output high.
    mov r4, r3
delay_on:
    subs r4, #1
    bne delay_on
    str r2, [r0]                          @ Set GPIOA pin5 output low.
    mov r4, r3
delay_off:
    subs r4, #1
    bne delay_off
    b blink_loop

    .end
