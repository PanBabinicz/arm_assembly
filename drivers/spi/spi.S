        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_spi.inc"

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
