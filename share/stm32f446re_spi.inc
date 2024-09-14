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
@---------------------------------- SPI CR2 register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ spi_cr2_rxdmaen_position,      (0x00)
        .equ spi_cr2_rxdmaen_mask,          (0x01 << spi_cr2_rxdmaen_position)
        .equ spi_cr2_rxdmaen,               (spi_cr2_rxdmaen_mask)

        .equ spi_cr2_txdmaen_position,      (0x01)
        .equ spi_cr2_txdmaen_mask,          (0x01 << spi_cr2_txdmaen_position)
        .equ spi_cr2_txdmaen,               (spi_cr2_txdmaen_mask)

        .equ spi_cr2_ssoe_position,         (0x02)
        .equ spi_cr2_ssoe_mask,             (0x01 << spi_cr2_ssoe_position)
        .equ spi_cr2_ssoe,                  (spi_cr2_ssoe_mask)

        .equ spi_cr2_frf_position,          (0x04)
        .equ spi_cr2_frf_mask,              (0x01 << spi_cr2_frf_position)
        .equ spi_cr2_frf,                   (spi_cr2_frf_mask)

        .equ spi_cr2_errie_position,        (0x05)
        .equ spi_cr2_errie_mask,            (0x01 << spi_cr2_errie_position)
        .equ spi_cr2_errie,                 (spi_cr2_errie_mask)

        .equ spi_cr2_rxneie_position,       (0x06)
        .equ spi_cr2_rxneie_mask,           (0x01 << spi_cr2_rxneie_position)
        .equ spi_cr2_rxneie,                (spi_cr2_rxneie_mask)

        .equ spi_cr2_txeie_position,        (0x07)
        .equ spi_cr2_txeie_mask,            (0x01 << spi_cr2_txeie_position)
        .equ spi_cr2_txeie,                 (spi_cr2_txeie_mask)


@-----------------------------------------------------------------------------------------------@
@---------------------------------- SPI SR register fields -------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ spi_sr_rxne_position,          (0x00)
        .equ spi_sr_rxne_mask,              (0x01 << spi_sr_rxne_position)
        .equ spi_sr_rxne,                   (spi_sr_rxne_mask)

        .equ spi_sr_txe_position,           (0x01)
        .equ spi_sr_txe_mask,               (0x01 << spi_sr_txe_position)
        .equ spi_sr_txe,                    (spi_sr_txe_mask)

        .equ spi_sr_chside_position,        (0x02)
        .equ spi_sr_chside_mask,            (0x01 << spi_sr_chside_position)
        .equ spi_sr_chside,                 (spi_sr_chside_mask)

        .equ spi_sr_udr_position,           (0x03)
        .equ spi_sr_udr_mask,               (0x01 << spi_sr_udr_position)
        .equ spi_sr_udr,                    (spi_sr_udr_mask)

        .equ spi_sr_crcerr_position,        (0x04)
        .equ spi_sr_crcerr_mask,            (0x01 << spi_sr_crcerr_position)
        .equ spi_sr_crcerr,                 (spi_sr_crcerr_mask)

        .equ spi_sr_modf_position,          (0x05)
        .equ spi_sr_modf_mask,              (0x01 << spi_sr_modf_position)
        .equ spi_sr_modf,                   (spi_sr_modf_mask)

        .equ spi_sr_ovr_position,           (0x06)
        .equ spi_sr_ovr_mask,               (0x01 << spi_sr_ovr_position)
        .equ spi_sr_ovr,                    (spi_sr_ovr_mask)

        .equ spi_sr_bsy_position,           (0x07)
        .equ spi_sr_bsy_mask,               (0x01 << spi_sr_bsy_position)
        .equ spi_sr_bsy,                    (spi_sr_bsy_mask)

        .equ spi_sr_fre_position,           (0x08)
        .equ spi_sr_fre_mask,               (0x01 << spi_sr_fre_position)
        .equ spi_sr_fre,                    (spi_sr_fre_mask)


@-----------------------------------------------------------------------------------------------@
@---------------------------------- SPI DR register fields -------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ spi_dr_dr_position,            (0x00)
        .equ spi_dr_dr_mask,                (0xffff << spi_dr_dr_position)
        .equ spi_dr_dr,                     (spi_dr_dr_mask)
        .equ spi_dr_dr_bit0,                (0x0001 << spi_dr_dr_position)
        .equ spi_dr_dr_bit1,                (0x0002 << spi_dr_dr_position)
        .equ spi_dr_dr_bit2,                (0x0004 << spi_dr_dr_position)
        .equ spi_dr_dr_bit3,                (0x0008 << spi_dr_dr_position)
        .equ spi_dr_dr_bit4,                (0x0010 << spi_dr_dr_position)
        .equ spi_dr_dr_bit5,                (0x0020 << spi_dr_dr_position)
        .equ spi_dr_dr_bit6,                (0x0040 << spi_dr_dr_position)
        .equ spi_dr_dr_bit7,                (0x0080 << spi_dr_dr_position)
        .equ spi_dr_dr_bit8,                (0x0100 << spi_dr_dr_position)
        .equ spi_dr_dr_bit9,                (0x0200 << spi_dr_dr_position)
        .equ spi_dr_dr_bit10,               (0x0400 << spi_dr_dr_position)
        .equ spi_dr_dr_bit11,               (0x0800 << spi_dr_dr_position)
        .equ spi_dr_dr_bit12,               (0x1000 << spi_dr_dr_position)
        .equ spi_dr_dr_bit13,               (0x2000 << spi_dr_dr_position)
        .equ spi_dr_dr_bit14,               (0x4000 << spi_dr_dr_position)
        .equ spi_dr_dr_bit15,               (0x8000 << spi_dr_dr_position)


@-----------------------------------------------------------------------------------------------@
