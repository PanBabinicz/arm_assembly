        .syntax unified
        .cpu cortex-m4
        .thumb

        .include "stm32f446re_spi.inc"

        spi_configure_result_success = 0x00
        spi_configure_result_error   = 0x01

        .text
        .balign 4
        .global _spi_configure_cr1
        .type _spi_configure_cr1, %function
        @ Argument in r0: spi base address
        @ Argument in r1: spi cr1 configuration
        @ NOTE:
        @ a) Configure the serial clock baud rate using the BR[2:0] bits:
        @       - Eight possible configurations (0 to 7)
        @ b) Configure CPOL and CPHA bits combination to define one of the four
        @    relationships between the data transfer and the serial clock
        @ c) Select simplex, half-duplex or full-duplex by configuring:
        @       - RXONLY
        @       - BIDIMODE
        @       - BDIOE
        @ d) Configure the LSBFIRST bit to define the frame format
        @ e) Configure the CRC if needed
        @ f) Configure SSM and SSI ( When the SSM bit is set, the NSS pin input is
        @    replaced with the value from the SSI bit)
        @ g) Configure MSTR bit
        @ h) Set the DFF bit to configure the data frame format (8 or 16 bits)
_spi_configure_cr1:
        ldr r2, [r0, #spi_cr1_offset]
        orr r2, r1
        str r2, [r0, #spi_cr1_offset]
        bx lr

        .text
        .balign 4
        .global _spi_configure_cr2
        .type _spi_configure_cr2, %function
        @ Argument in r0: spi base address
        @ Argument in r1: spi cr2 configuration
        @ NOTE:
        @ a) Configure SSOE
        @ b) Set the FRF bit if the TI protocol is required
_spi_configure_cr2:
        ldr r2, [r0, #spi_cr2_offset]
        orr r2, r1
        str r2, [r0, #spi_cr2_offset]
        bx lr

        .text
        .balign 4
        .global _spi_configure_crcpr
        .type _spi_configure_crcpr, %function
        @ Argument in r0: spi base address
        @ Argument in r1: spi crcpr configuration
_spi_configure_crcpr:
        ldr r2, [r0, #spi_crcpr_offset]
        orr r2, r1
        str r2, [r0, #spi_crcpr_offset]
        bx lr

        .text
        .balign 4
        .global _spi_configure_dma
        .type _spi_configure_dma, %function
        @ Argument in r0: spi base address
        @ Argument in r1: dma base address
        @ NOTE:
        @ 1) Enable DMA Rx buffer in the RXDMAEN bit in the SPI_CR2 register,
        @    if DMA Rx is used
        @ 2) Enable DMA streams for Tx and Rx in DMA registers, if the streams
        @    are used
        @ 3) Enable DMA Tx buffer in the TXDMAEN bit in the SPI_CR2 register,
        @    if DMA Tx is used
        @ 4) Enable the SPI by setting the SPE bit
_spi_configure_dma:
        bx lr

        .text
        .balign 4
        .global _spi_enable
        .type _spi_enable, %function
        @ Argument in r0: spi base address
_spi_enable:
        ldr r1, [r0, #spi_cr1_offset]
        orr r1, #spi_cr1_spe
        str r1, [r0, #spi_cr1_offset]
        bx lr

        .text
        .balign 4
        .global _spi_disable
        .type _spi_disable, %function
        @ Argument in r0: spi base address
_spi_disable:
        ldr r1, [r0, #spi_cr1_offset]
        bic r1, #spi_cr1_spe
        str r1, [r0, #spi_cr1_offset]
        bx lr

        .text
        .balign 4
        .global _spi_send
        .type _spi_send, %function
        @ Argument in r0: spi base address
        @ Argument in r1:
        @ Argument in r2:
_spi_send:
        bx lr

        .text
        .balign 4
        .global _spi_receive
        .type _spi_receive, %function
        @ Argument in r0: spi base address
        @ Argument in r1:
        @ Argument in r2:
_spi_receive:
        bx lr

        .end
