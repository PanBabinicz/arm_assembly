        .syntax unified
        .cpu cortex-m4
        .thumb

        .text
        .global _reset_handler
        .type _reset_handler, %function
_reset_handler:
        bl _main
        b .             @ Never return.

        .text
        .type _main, %function
_main:
        nop
        b .             @ Never return.

        .end
