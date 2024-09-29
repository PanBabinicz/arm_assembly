        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_i2c.inc"

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
        lsl r4, r2, #0x01               @ 2*fscl
        ldr r3, =0x000186a0             @ 100kHz
        cmp r2, r3
        itte hi
        addhi r4, r2                    @ 3*fscl
        movhi r5, #0x01                 @ Fast mode
        movls r5, #0x00                 @ Standard mode
        udiv r6, r1, r4                 @ fpclk / x*fscl
        lsl r5, #0x0f                   @ shift f/s bit on 15th position
        orr r6, r5
        str r6, [r0, #i2c_ccr_offset]
i2c_configure_clock_exit:
        pop { r4-r7 }
        bx lr

        .text
        .balign 4
        .type _i2c_configure_rise_time, %function
        @ Argument in r0: i2c base address
        @ Argument in r1: i2c clock frequency (2MHz, 50MHz)
        @ Argument in r2: i2c scl frequency (0, 100kHz) or (100kHz, 400kHz)
_i2c_configure_rise_time:
        push { r4 }
        sub sp, sp, #0x04
        ldr r3, =0x000186a0             @ 100kHz
        cmp r2, r3
        ittt hi
        movhi r3, #0x012c               @ 300ns
        mulhi r4, r1, r3                @ trise = clock_frequency * r3
        lsrhi r4, r4, #0x0a             @ divide by 1024
        itt ls
        movls r3, #0x01                 @ 1us
        mulls r4, r1, r3                @ trise = clock_frequency * r3
        add r4, r4, #0x01
        str r4, [r0, #i2c_trise_offset]
        add sp, sp, #0x04
        pop { r4 }
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
        ldr r3, =0x001e8480             @ 2MHz
        cmp r1, r3
        itt lo
        movlo r0, #0x01                 @ Error: clock frequency is less than 2MHz
        blo i2c_check_arguments_exit
        ldr r3, =0x02faf080             @ 50MHz
        cmp r1, r3
        itt hi
        movhi r0, #0x01                 @ Error: clock frequency is greater than 50MHz
        bhi i2c_check_arguments_exit
        ldr r3, =0x00                   @ 0Hz
        cmp r2, r3
        itt eq
        moveq r0, #0x01                 @ Error: scl frequency is equal 0Hz
        beq i2c_check_arguments_exit
        ldr r3, =0x00061a80             @ 400kHz
        cmp r2, r3
        itt hi
        movhi r0, #0x01                 @ Error: scl frequency is greater than 400kHz
        bhi i2c_check_arguments_exit
        mov r0, #0x00                   @ Success: clock and scl frequencies are okey
i2c_check_arguments_exit:
        bx lr

        .text
        .balign 4
        .type _i2c_master_transmit_byte, %function
        @ Argument in r0: i2c base address
        @ Argument in r1: data byte
_i2c_master_transmit_byte:
        ldrb r2, [r1], #1
        strb r2, [r0, #i2c_dr_offset]
        bx lr

        .text
        .balign 4
        .type _i2c_master_receive_byte, %function
        @ Argument in r0: i2c base address
        @ Argument in r1: data buffer address
_i2c_master_receive_byte:
        ldrb r2, [r0, #i2c_dr_offset]
        strb r2, [r1], #1
        bx lr

        .text
        .balign 4
        .global _i2c_master_transmit
        .type _i2c_master_transmit, %function
        @ Argument in r0: i2c base address / i2c init status
        @ Argument in r1: data
        @ Argument in r2: slave address
_i2c_master_transmit:
        push { r4, lr }
        ldr r3, [r0, #i2c_cr1_offset]
        orr r3, #i2c_cr1_start
        str r3, [r0, #i2c_cr1_offset]   @ Start generation
i2c_master_transmit_check_sb:
        ldr r3, [r0, #i2c_sr1_offset]
        tst r3, #i2c_sr1_sb
        it eq
        beq i2c_master_transmit_check_sb
        lsl r2, #0x01                   @ Shift the address, lsb signals the mode
        bic r2, #0x01                   @ Enter the transmitter mode
        strb r2, [r0, #i2c_dr_offset]
i2c_master_transmit_check_addr:
        ldr r3, [r0, #i2c_sr1_offset]
        tst r3, #i2c_sr1_addr
        it eq
        beq i2c_master_transmit_check_addr
        ldr r3, [r0, #i2c_sr2_offset]   @ Read sr2 after sr1 to clear the addr
i2c_master_transmit_next_byte:
        cmp r1, #0x00
        it eq
        beq i2c_master_transmit_check_btf
        bl _i2c_master_transmit_byte    @ Don't need to save r2 because I dont use it anymore
i2c_master_transmit_is_empty:
        ldr r3, [r0, #i2c_sr1_offset]
        tst r3, #i2c_sr1_txe
        it ne
        bne i2c_master_transmit_next_byte
        it eq
        beq i2c_master_transmit_is_empty
i2c_master_transmit_check_btf:
        ldr r3, [r0, #i2c_sr1_offset]
        tst r3, #i2c_sr1_btf
        it eq
        beq i2c_master_transmit_check_btf
        ldr r3, [r0, #i2c_cr1_offset]
        orr r3, #i2c_cr1_stop
        str r3, [r0, #i2c_cr1_offset]
        pop { r4, lr }
        bx lr

        .text
        .balign 4
        .global _i2c_master_receive
        .type _i2c_master_receive, %function
        @ Argument in r0: i2c base address / i2c init status
        @ Argument in r1: data buffer address
        @ Argument in r2: data buffer size
        @ Argument in r3: slave address
_i2c_master_receive:
        push { r4-r5, lr }
        sub sp, sp, #0x04
        mov r5, r2                      @ Save the data buffer size
        ldr r4, [r0, #i2c_cr1_offset]
        orr r4, #i2c_cr1_start
        str r4, [r0, #i2c_cr1_offset]   @ Start generation
i2c_master_receive_check_sb:
        ldr r4, [r0, #i2c_sr1_offset]
        tst r4, #i2c_sr1_sb
        it eq
        beq i2c_master_receive_check_sb
        lsl r3, #0x01                   @ Shift the address, lsb signals the mode
        orr r3, #0x01                   @ Enter the receiver mode
        strb r3, [r0, #i2c_dr_offset]
i2c_master_receive_check_addr:
        ldr r4, [r0, #i2c_sr1_offset]
        tst r4, #i2c_sr1_addr
        it eq
        beq i2c_master_receive_check_addr
        ldr r4, [r0, #i2c_sr2_offset]   @ Read sr2 after sr1 to clear the addr
i2c_master_receive_next_byte:
1:
        ldr r4, [r0, #i2c_sr1_offset]
        tst r4, #i2c_sr1_rxne
        it eq
        beq 1b                          @ Wait for the data to be available in buffer
        subs r5, #0x01
        bl _i2c_master_receive_byte
        cmp r5, #0x01
        it ne
        bne i2c_master_receive_next_byte
        ldr r4, [r0, #i2c_cr1_offset]   @ Prepare the NACK
        bic r4, #i2c_cr1_ack
        str r4, [r0, #i2c_cr1_offset]
2:
        ldr r4, [r0, #i2c_sr1_offset]
        tst r4, #i2c_sr1_rxne
        it eq
        beq 2b                          @ Wait for the data to be available in buffer
        bl _i2c_master_receive_byte     @ Receive the last byte
        ldr r4, [r0, #i2c_cr1_offset]
        orr r4, #i2c_cr1_stop           @ Set STOP
        str r4, [r0, #i2c_cr1_offset]
        add sp, sp, #0x04
        pop { r4-r5, lr }
        bx lr

        .text
        .balign 4
        .global _i2c_slave_transmit
        .type _i2c_slave_transmit, %function
        @ Argument in r0: i2c base address / i2c init status
        @ Argument in r1: data
        @ Argument in r2: slave address
_i2c_slave_transmit:

        .text
        .balign 4
        .global _i2c_slave_receive
        .type _i2c_slave_receive, %function
_i2c_slave_receive:

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
        cmp r0, #0x00
        it ne
        bne i2c_init_exit
        mov r0, r4
        bl _i2c_set_peripheral_input_clock
        bl _i2c_configure_clock
        bl _i2c_configure_rise_time
        bl _i2c_enable
i2c_init_exit:
        pop { r4, lr }
        bx lr

        .end
