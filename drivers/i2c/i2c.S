        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32446re_i2c.inc"

        .text
        .balign 4
        .type _i2c_set_peripheral_input_clock, %function
        @ Argument in r0: i2c base address
        @ Argument in r1: i2c clock frequency
_i2c_set_peripheral_input_clock:
        str r1, [r0, #i2c_cr2_offset]
        bx lr

        .text
        .balign 4
        .type _i2c_configure_clock, %function
_i2c_configure_clock:

        .text
        .balign 4
        .type _i2c_configure_rise_time, %function
        @ Argument in r0: i2c base address
        @ Argument in r1: i2c rise time value
_i2c_configure_rise_time:
        str r1, [r0, #i2c_trise_offset]
        bx lr

        .text
        .balign 4
        .type _i2c_enable, %function
        @ Argument in r0: i2c base address
_i2c_enable:
        ldr r1, [r0, #i2c_cr1_offset]
        orr r1, #i2c_cr1_pe
        str r1, [r0, #i2c_cr1_offset]
        bx lr

        .text
        .balign 4
        .global _i2c_init
        .type _i2c_init, %function
        @ Argument in r0: i2c base address
_i2c_init:
        push { lr }             @ Push only 4 bytes.
        sub sp, sp, #4          @ Adjust to maintain 8-byte alignment.
        bl _i2c_set_peripheral_input_clock
        bl _i2c_configure_clock
        bl _i2c_configure_rise_time
        bl _i2c_enable
        add sp, sp, #4          @ Restore stack pointer before returning.
        pop { lr }

        .end
