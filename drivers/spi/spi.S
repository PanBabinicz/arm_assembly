        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_spi.inc"

        spi_configure_result_success = 0x00
        spi_configure_result_error   = 0x01

        .text
        .balign 4
        .type _spi_configure_serial_clock_baudrate, %function
        @ Argument in r0: spi base address / spi configure status
        @ Argument in r1: serial clock baud rate (3 bit value)
_spi_configure_serial_clock_baudrate:
        cmp r1, #0x00
        it hi
        cmphi r1, #0x07
        itt hi
        movhi r0, #spi_configure_result_error
        bhi spi_configure_serial_clock_baudrate_exit
        ldr r2, [r0, #spi_cr1_offset]
        lsl r1, #spi_cr1_br_position
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
spi_configure_serial_clock_baudrate_exit:
        bx lr

        .text
        .balign 4
        .type _spi_configure_clock_polarity, %function
        @ Argument in r0: spi base address / spi configure status
        @ Argument in r1: clock polarity (1 bit value)
_spi_configure_clock_polarity:
        cmp r1, #0x00
        it hi
        cmphi r1, #0x01
        itt hi
        movhi r0, #spi_configure_result_error
        bhi spi_configure_clock_polarity_exit
        ldr r2, [r0, #spi_cr1_offset]
        lsl r1, #spi_cr1_cpol_position
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
spi_configure_clock_polarity_exit:
        bx lr

        .text
        .balign 4
        .type _spi_configure_clock_phase, %function
        @ Argument in r0: spi base address / spi configure status
        @ Argument in r1: clock phase (1 bit value)
_spi_configure_clock_phase:
        cmp r1, #0x00
        it hi
        cmphi r1, #0x01
        itt hi
        movhi r0, spi_configure_result_error
        bhi spi_configure_clock_phase_exit
        ldr r2, [r0, #spi_cr1_offset]
        lsl r1, #spi_cr1_cpha_position
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        mov r0, spi_configure_result_success
spi_configure_clock_phase_exit:
        bx lr

        .text
        .balign 4
        .type _spi_configure_duplex, %function
        @ Argument in r0: spi base address / spi configure status
        @ Argument in r1: half-duplex (1) or full-duplex (0)
_spi_configure_duplex:
        cmp r1, #0x00
        it hi
        cmphi r1, #0x01
        itt hi
        movhi r0, spi_configure_result_error
        bhi spi_configure_duplex_exit
        ldr r2, [r0, #spi_cr1_offset]
        ite eq                                   @ If r1 is 0
        biceq r2, #(spi_cr1_bidimode | spi_cr1_rxonly)
        orrne r2, #(spi_cr1_bidimode | spi_cr1_rxonly)
        str r2, [r0, #spi_cr1_offset]
        mov r0, spi_configure_result_success
spi_configure_duplex_exit:
        bx lr

        .text
        .balign 4
        .type _spi_configure_simplex, %function
_spi_configure_simplex:
        bx lr

        .text
        .balign 4
        .type _spi_configure_frame_format, %function
_spi_configure_frame_format:
        bx lr

        .text
        .balign 4
        .type _spi_configure_crc, %function
_spi_configure_crc:
        bx lr

        .text
        .balign 4
        .type _spi_configure_ssm, %function
_spi_configure_ssm:
        bx lr

        .text
        .balign 4
        .type _spi_configure_ssi, %function
_spi_configure_ssi:
        bx lr

        .text
        .balign 4
        .type _spi_configure_mode, %function
_spi_configure_mode:
        bx lr

        .text
        .balign 4
        .type _spi_configure_data_frame_format, %function
_spi_configure_data_frame_format:
        bx lr

        .text
        .balign 4
        .type _spi_configure_ssoe, %function
_spi_configure_ssoe:
        bx lr

        .text
        .balign 4
        .global _spi_init_slave
        .type _spi_init_slave, %function
        @ Argument in r0: spi base address / spi init status
        @ Argument in r1:
        @ Argument in r2:
_spi_init_slave:
        push { lr }
        sub sp, sp, #0x04
        add sp, sp, #0x04
        pop { lr }
        bx lr

        .text
        .balign 4
        .global _spi_init_master
        .type _spi_init_master, %function
        @ Argument in r0: spi base address / spi init status
        @ Argument in r1:
        @ Argument in r2:
_spi_init_master:
        push { lr }
        sub sp, sp, #0x04
        bl _spi_configure_serial_clock_baudrate
        add sp, sp, #0x04
        pop { lr }
        bx lr

        .end
