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
        ldr r3, =0x001e8480     @ 2MHz
        cmp r1, r3
        it lo
        blo i2c_configure_clock_exit
        ldr r3, =0x02faf080     @ 50MHz
        cmp r1, r3
        it hi
        bhi i2c_configure_clock_exit
        ldr r3, =0x00           @ 0Hz
        cmp r2, r3
        it eq
        beq i2c_configure_clock_exit
        ldr r3, =0x000186a0     @ 100kHz
        cmp r2, r3
        it hi
        bhi i2c_configure_clock_check_fm
        mov r6, #0x00           @ Standard mode
        b i2c_configure_clock_calculate_ccr
i2c_configure_clock_check_fm:
        ldr r3, =0x00061a80     @ 400kHz
        cmp r2, r3
        it hi
        bhi i2c_configure_clock_exit
        mov r6, #0x01           @ Fast mode
i2c_configure_clock_calculate_ccr:
        lsl r5, r2, #0x01       @ 2*fscl
        cmp r3, #0x00
        it ne
        addne r5, r5, r2        @ 3*fscl
        udiv r4, r1, r5         @ fpclk / x*fscl
        lsl r6, #0x0f           @ shift f/s bit on 15th position
        orr r4, r6
        str r4, [r0, #i2c_ccr_offset]
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
