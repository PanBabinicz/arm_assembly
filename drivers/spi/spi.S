        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_spi.inc"

        .text
        .balign 4
        .type _spi_configure_serial_clock_baudrate, %function
_spi_configure_serial_clock_baudrate:
        bx lr

        .text
        .balign 4
        .type _spi_configure_clock_polarity, %function
_spi_configure_clock_polarity:
        bx lr

        .text
        .balign 4
        .type _spi_configure_clock_phase, %function
_spi_configure_clock_phase:
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
        .global _spi_init
        .type _spi_init, %function
        @ Argument in r0: spi base address / spi init status
        @ Argument in r1:
        @ Argument in r2:
_spi_init:
        push { lr }
        sub sp, sp, #0x04
        add sp, sp, #0x04
        pop { lr }
        bx lr

        .end
