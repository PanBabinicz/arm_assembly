        .syntax unified
        .cpu cortex-m4
        .thumb


@-----------------------------------------------------------------------------------------------@
@---------------------------------- SPI registers offsets --------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ spi1_base,                     (0x40013000)    @ SPI1 register boundary address
        .equ spi2_base,                     (0x40003800)    @ SPI2 register boundary address
        .equ spi3_base,                     (0x40003c00)    @ SPI3 register boundary address
        .equ spi4_base,                     (0x40013400)    @ SPI4 register boundary address

        .equ spi_cr1_offset,                (0x00)          @ SPI control register 1 offset
        .equ spi_cr2_offset,                (0x04)          @ SPI control register 2 offset
        .equ spi_sr_offset,                 (0x08)          @ SPI status register offset
        .equ spi_dr_offset,                 (0x0c)          @ SPI data register offset
        .equ spi_crcpr_offset,              (0x10)          @ SPI crc polynomial register offset
        .equ spi_rxcrcr_offset,             (0x14)          @ SPI rx crc register offset
        .equ spi_txcrcr_offset,             (0x18)          @ SPI tx crc register offset
        .equ spi_i2scfgr_offset,            (0x1c)          @ SPI spi_i2s configuration
                                                            @ register 2 offset

        .equ spi_i2spr_offset,              (0x20)          @ SPI spi_i2s prescaler register
                                                            @ offset


@-----------------------------------------------------------------------------------------------@
