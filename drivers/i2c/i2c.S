        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32446re_i2c.inc"

        .text
        .balign 4
        .type _i2c_set_peripheral_input_clock, %function
        @ Argument in r0: i2c base address
        @ Argument in r1: i2c clock frequency (2MHz, 50MHz)
_i2c_set_peripheral_input_clock:
        str r1, [r0, #i2c_cr2_offset]
        bx lr

        .text
        .balign 4
        .type _i2c_configure_clock, %function
        @ Argument in r0: i2c base address
        @ Argument in r1: i2c clock frequency (2MHz, 50MHz)
        @ Argument in r2: i2c scl frequency (0, 100kHz) or (100kHz, 400kHz)
_i2c_configure_clock:
        push { r4-r7 }
        lsl r4, r2, #0x01       @ 2*fscl
        ldr r3, =0x000186a0     @ 100kHz
        cmp r2, r3
        itt hi
        addhi r4, r2            @ 3*fscl
        movhi r5, #0x01         @ Fast mode
        mov r5, #0x00           @ Standard mode
        udiv r6, r1, r4         @ fpclk / x*fscl
        lsl r5, #0x0f           @ shift f/s bit on 15th position
        orr r6, r5
        str r6, [r0, #i2c_ccr_offset]
i2c_configure_clock_exit:
        pop { r4-r7 }
        bx lr

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
        .type _i2c_check_arguments, %function
        @ Argument in r0: i2c check argument status
        @ Argument in r1: i2c clock frequency (2MHz, 50MHz)
        @ Argument in r2: i2c scl frequency (0, 100kHz) or (100kHz, 400kHz)
_i2c_check_arguments:
        ldr r3, =0x001e8480     @ 2MHz
        cmp r1, r3
        itt lo
        movhi r0, #0x01         @ Error: clock frequency is less than 2MHz
        blo i2c_check_arguments_exit
        ldr r3, =0x02faf080     @ 50MHz
        cmp r1, r3
        itt hi
        movhi r0, #0x01         @ Error: clock frequency is greater than 50MHz
        bhi i2c_check_arguments_exit
        ldr r3, =0x00           @ 0Hz
        cmp r2, r3
        itt eq
        moveq r0, #0x01         @ Error: scl frequency is equal 0Hz
        beq i2c_check_arguments_exit
        ldr r3, =0x00061a80     @ 400kHz
        cmp r2, r3
        itt hi
        movhi r0, #0x01         @ Error: scl frequency is greater than 400kHz
        bhi i2c_check_arguments_exit
        mov r0, #0x00           @ Success: clock and scl frequencies are okey
i2c_check_arguments_exit:
        bx lr

        .text
        .balign 4
        .global _i2c_init
        .type _i2c_init, %function
        @ Argument in r0: i2c base address / i2c init status
        @ Argument in r1: i2c clock frequency (2MHz, 50MHz)
        @ Argument in r2: i2c scl frequency (0, 100kHz) or (100kHz, 400kHz)
_i2c_init:
        push { r4, lr }
        mov r4, r0
        bl _i2c_check_arguments
        bl _i2c_set_peripheral_input_clock
        bl _i2c_configure_clock
        bl _i2c_configure_rise_time
        bl _i2c_enable
        pop { r4, lr }

        .end
