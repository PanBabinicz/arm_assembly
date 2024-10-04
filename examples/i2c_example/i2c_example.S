        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_rcc.inc"
        .include "stm32f446re_gpio.inc"
        .include "stm32f446re_i2c.inc"

        .global _i2c_init
        .global _i2c_master_transmit

        i2c1_base_address    = i2c1_base
        i2c1_clock_frequency = 0x00f42400       @ 16MHz
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
        ldr r0, =rcc_base
        ldr r1, [r0, #rcc_apb1enr_offset]
        orr r1, #rcc_apb1enr_i2c1en
        str r1, [r0, #rcc_apb1enr_offset]       @ Set the clock on i2c1
        ldr r1, [r0, #rcc_ahb1enr_offset]
        orr r1, #rcc_ahb1enr_gpioben
        str r1, [r0, #rcc_ahb1enr_offset]       @ Set the clock on gpiob
        bx lr

        .text
        .balign 4
        .type _gpio_setup, %function
_gpio_setup:
        ldr r0, =gpiob_base
        ldr r1, [r0, #gpiox_moder_offset]
        orr r1, #(gpiox_moder_moder8_bit1 | gpiox_moder_moder9_bit1)
        str r1, [r0, #gpiox_moder_offset]
        ldr r1, [r0, #gpiox_pupdr_offset]
        orr r1, #(gpiox_pupdr_pupdr8_bit0 | gpiox_pupdr_pupdr9_bit0)
        str r1, [r0, #gpiox_pupdr_offset]
        ldr r1, [r0, #gpiox_afrh_offset]
        orr r1, #(gpiox_afrh_afrh8_bit2 | gpiox_afrh_afrh9_bit2)
        str r1, [r0, #gpiox_afrh_offset]
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
