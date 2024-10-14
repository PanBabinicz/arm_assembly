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
        movhi r0, #spi_configure_result_error
        bhi spi_configure_clock_phase_exit
        ldr r2, [r0, #spi_cr1_offset]
        lsl r1, #spi_cr1_cpha_position
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
spi_configure_clock_phase_exit:
        bx lr

        .text
        .balign 4
        .type _spi_configure_full_duplex, %function
        @ Argument in r0: spi base address / spi configure status
_spi_configure_full_duplex:
        ldr r1, [r0, #spi_cr1_offset]
        bic r1, #(spi_cr1_bidimode | spi_cr1_rxonly)
        str r1, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
        bx lr

        .text
        .balign 4
        .type _spi_configure_half_duplex_master, %function
        @ Argument in r0: spi base address / spi configure status
_spi_configure_half_duplex_master:
        ldr r1, [r0, #spi_cr1_offset]
        orr r1, #(spi_cr1_bidimode | spi_cr1_bidioe)
        bic r1, #spi_cr1_rxonly
        str r1, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
        bx lr

        .text
        .balign 4
        .type _spi_configure_half_duplex_slave, %function
        @ Argument in r0: spi base address / spi configure status
_spi_configure_half_duplex_slave:
        ldr r1, [r0, #spi_cr1_offset]
        orr r1, #(spi_cr1_bidimode | spi_cr1_rxonly)
        bic r1, #spi_cr1_bidioe
        str r1, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
        bx lr

        .text
        .balign 4
        .type _spi_configure_simplex_master, %function
        @ Argument in r0: spi base address / spi configure status
_spi_configure_simplex_master:
        ldr r1, [r0, #spi_cr1_offset]
        bic r1, #(spi_cr1_bidimode | spi_cr1_rxonly)
        orr r1, #spi_cr1_bidioe
        str r1, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
        bx lr

        .text
        .balign 4
        .type _spi_configure_simplex_slave, %function
        @ Argument in r0: spi base address / spi configure status
_spi_configure_simplex_slave:
        ldr r1, [r0, #spi_cr1_offset]
        bic r1, #(spi_cr1_bidimode | spi_cr1_bidioe)
        orr r1, #spi_cr1_rxonly
        str r1, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
        bx lr

        .text
        .balign 4
        .type _spi_configure_frame_format, %function
        @ Argument in r0: spi base address / spi configure status
        @ Argument in r1: frame format (msb first 0, lsb first 1)
_spi_configure_frame_format:
        cmp r1, #0x00
        it hi
        cmphi r1, #0x01
        itt hi
        movhi r0, #spi_configure_result_error
        bhi spi_configure_frame_format_exit
        ldr r2, [r0, #spi_cr1_offset]
        lsl r1, #spi_cr1_lsbfirst_position
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
spi_configure_frame_format_exit:
        bx lr

        .text
        .balign 4
        .type _spi_configure_crc, %function
_spi_configure_crc:
        bx lr

        .text
        .balign 4
        @ Argument in r0: spi base address / spi configure status
        @ Argument in r1: software slave management (disabled 0, enabled 1)
        .type _spi_configure_ssm, %function
_spi_configure_ssm:
        cmp r1, #0x00
        it hi
        cmphi r1, #0x01
        itt hi
        movhi r0, #spi_configure_result_error
        bhi spi_configure_ssm_exit
        ldr r2, [r0, #spi_cr1_offset]
        lsl r1, #spi_cr1_ssm_position
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
spi_configure_ssm_exit:
        bx lr

        .text
        .balign 4
        .type _spi_configure_ssi, %function
        @ Argument in r0: spi base address / spi configure status
        @ Argument in r1: internal slave select (works only when ssm is set)
        @ NOTE: The value of this bit is forced onto the NSS pin and the IO value of
        @       the NSS pin is ignored
_spi_configure_ssi:
        cmp r1, #0x00
        it hi
        cmphi r1, #0x01
        itt hi
        movhi r0, #spi_configure_result_error
        bhi spi_configure_ssi_exit
        ldr r2, [r0, #spi_cr1_offset]
        lsl r1, #spi_cr1_ssi_position
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        mov r0, #spi_configure_result_success
spi_configure_ssi_exit:
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
