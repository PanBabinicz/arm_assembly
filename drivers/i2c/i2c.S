        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32446re_i2c.inc"

        .text
        .balign 4
        .type _i2c_set_peripheral_input_clock, %function
_i2c_set_peripheral_input_clock:

        .text
        .balign 4
        .type _i2c_configure_clock, %function
_i2c_configure_clock:

        .text
        .balign 4
        .type _i2c_configure_rise_time, %function
_i2c_configure_rise_time:

        .text
        .balign 4
        .type _i2c_enable, %function
_i2c_enable:

        .text
        .balign 4
        .global _i2c_init
        .type _i2c_init, %function
        @ Argument in r0: i2c base address
_i2c_init:
        push { lr }             @ Push only 4 bytes.
        bl _i2c_set_peripheral_input_clock
        bl _i2c_configure_clock
        bl _i2c_configure_rise_time
        bl _i2c_enable
        sub sp, sp, #4          @ Adjust to maintain 8-byte alignment.
        add sp, sp, #4          @ Restore stack pointer before returning.
        pop { lr }

        .end
