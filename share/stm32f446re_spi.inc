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
@---------------------------------- SPI CR1 register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ spi_cr1_cpha_position,         (0x00)
        .equ spi_cr1_cpha_mask,             (0x01 << spi_cr1_cpha_position)
        .equ spi_cr1_cpha,                  (spi_cr1_cpha_mask)

        .equ spi_cr1_cpol_position,         (0x01)
        .equ spi_cr1_cpol_mask,             (0x01 << spi_cr1_cpol_position)
        .equ spi_cr1_cpol,                  (spi_cr1_cpol_mask)

        .equ spi_cr1_mstr_position,         (0x02)
        .equ spi_cr1_mstr_mask,             (0x01 << spi_cr1_mstr_position)
        .equ spi_cr1_mstr,                  (spi_cr1_mstr_mask)

        .equ spi_cr1_br_position,           (0x03)
        .equ spi_cr1_br_mask,               (0x07 << spi_cr1_br_position)
        .equ spi_cr1_br,                    (spi_cr1_br_mask)
        .equ spi_cr1_br_bit0,               (0x01 << spi_cr1_br_position)
        .equ spi_cr1_br_bit1,               (0x02 << spi_cr1_br_position)
        .equ spi_cr1_br_bit2,               (0x04 << spi_cr1_br_position)

        .equ spi_cr1_spe_position,          (0x06)
        .equ spi_cr1_spe_mask,              (0x01 << spi_cr1_spe_position)
        .equ spi_cr1_spe,                   (spi_cr1_spe_mask)

        .equ spi_cr1_lsbfirst_position,     (0x07)
        .equ spi_cr1_lsbfirst_mask,         (0x01 << spi_cr1_lsbfirst_position)
        .equ spi_cr1_lsbfirst,              (spi_cr1_lsbfirst_mask)

        .equ spi_cr1_ssi_position,          (0x08)
        .equ spi_cr1_ssi_mask,              (0x01 << spi_cr1_ssi_position)
        .equ spi_cr1_ssi,                   (spi_cr1_ssi_mask)

        .equ spi_cr1_ssm_position,          (0x09)
        .equ spi_cr1_ssm_mask,              (0x01 << spi_cr1_ssm_position)
        .equ spi_cr1_ssm,                   (spi_cr1_ssm_mask)

        .equ spi_cr1_rxonly_position,       (0x0a)
        .equ spi_cr1_rxonly_mask,           (0x01 << spi_cr1_rxonly_position)
        .equ spi_cr1_rxonly,                (spi_cr1_rxonly_mask)

        .equ spi_cr1_dff_position,          (0x0b)
        .equ spi_cr1_dff_mask,              (0x01 << spi_cr1_dff_position)
        .equ spi_cr1_dff,                   (spi_cr1_dff_mask)

        .equ spi_cr1_crcnext_position,      (0x0c)
        .equ spi_cr1_crcnext_mask,          (0x01 << spi_cr1_crcnext_position)
        .equ spi_cr1_crcnext,               (spi_cr1_crcnext_mask)

        .equ spi_cr1_crcen_position,        (0x0d)
        .equ spi_cr1_crcen_mask,            (0x01 << spi_cr1_crcen_position)
        .equ spi_cr1_crcen,                 (spi_cr1_crcen_mask)

        .equ spi_cr1_bidioe_position,       (0x0e)
        .equ spi_cr1_bidioe_mask,           (0x01 << spi_cr1_bidioe_position)
        .equ spi_cr1_bidioe,                (spi_cr1_bidioe_mask)

        .equ spi_cr1_bidimode_position,     (0x0f)
        .equ spi_cr1_bidimode_mask,         (0x01 << spi_cr1_bidimode_position)
        .equ spi_cr1_bidimode,              (spi_cr1_bidimode_mask)


@-----------------------------------------------------------------------------------------------@
