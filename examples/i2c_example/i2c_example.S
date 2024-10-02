        .syntax unified
        .cpu cortex-m4
        .thumb

        i2c1_base_address    = i2c1_base
        i2c1_clock_frequency = 0x02625a00       @ 40MHz
        i2c1_scl_frequency   = 0x000493e0       @ 300kHz

        i2c_slave_address    = 0x62             @ Slave address

        .section .rodata
        .balign 4
        .type i2c_data_start, %object
i2c_data_start:
        .byte 0x01
        .byte 0x02
        .byte 0x03
        .byte 0x04
        .byte 0x05
        .byte 0x06
        .byte 0x07
        .byte 0x08

        .text
        .balign 4
        .global _reset_handler
        .type _reset_handler, %function
_reset_handler:
        bl _rcc_setup
        bl _gpio_setup
        bl _main
        b .                                     @ Never return

        .text
        .balign 4
        .type _rcc_setup, %function
_rcc_setup:
        bx lr

        .text
        .balign 4
        .type _gpio_setup, %function
_gpio_setup:
        bx lr

        .text
        .balign 4
        .type _main, %function
_main:
        push { lr }
        sub sp, sp, #0x04
        ldr r0, =i2c1_base_address
        ldr r1, =i2c1_clock_frequency
        ldr r2, =i2c1_scl_frequency
        bl _i2c_init
        ldr r1, =i2c_data_start
        ldr r2, =i2c_slave_address
        bl _i2c_master_transmit
1:
        wfi
        b 1b
        add sp, sp, #0x04                       @ Should never go here
        pop { lr }
        bx lr

        .end
