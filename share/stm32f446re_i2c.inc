        .syntax unified
        .cpu cortex-m4
        .thumb


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C registers offsets --------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c1_base,                     (0x40005400)    @ I2C1 register boundary address
        .equ i2c2_base,                     (0x40005800)    @ I2C2 register boundary address
        .equ i2c3_base,                     (0x40005c00)    @ I2C3 register boundary address

        .equ i2c_cr1_offset,                (0x00)          @ I2C control register 1 offset
        .equ i2c_cr2_offset,                (0x04)          @ I2C control register 2 offset
        .equ i2c_oar1_offset,               (0x08)          @ I2C own address register 1 offset
        .equ i2c_oar2_offset,               (0x0c)          @ I2C own address register 2 offset
        .equ i2c_dr_offset,                 (0x10)          @ I2C data register offset
        .equ i2c_sr1_offset,                (0x14)          @ I2C status register 1 offset
        .equ i2c_sr2_offset,                (0x18)          @ I2C status register 2 offset
        .equ i2c_ccr_offset,                (0x1c)          @ I2C clock control register offset
        .equ i2c_trise_offset,              (0x20)          @ I2C TRISE register offset
        .equ i2c_fltr_offset,               (0x24)          @ I2C FLTR register offset


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C CR1 register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c_cr1_pe_position,           (0x00)
        .equ i2c_cr1_pe_mask,               (0x01 << i2c_cr1_pe_position)
        .equ i2c_cr1_pe,                    (i2c_cr1_pe_mask)

        .equ i2c_cr1_smbus_position,        (0x01)
        .equ i2c_cr1_smbus_mask,            (0x01 << i2c_cr1_smbus_position)
        .equ i2c_cr1_smbus,                 (i2c_cr1_smbus_mask)

        .equ i2c_cr1_smbtype_position,      (0x03)
        .equ i2c_cr1_smbtype_mask,          (0x01 << i2c_cr1_smbtype_position)
        .equ i2c_cr1_smbtype,               (i2c_cr1_smbtype_mask)

        .equ i2c_cr1_enarp_position,        (0x04)
        .equ i2c_cr1_enarp_mask,            (0x01 << i2c_cr1_enarp_position)
        .equ i2c_cr1_enarp,                 (i2c_cr1_enarp_mask)

        .equ i2c_cr1_enpec_position,        (0x05)
        .equ i2c_cr1_enpec_mask,            (0x01 << i2c_cr1_enpec_position)
        .equ i2c_cr1_enpec,                 (i2c_cr1_enpec_mask)

        .equ i2c_cr1_engc_position,         (0x06)
        .equ i2c_cr1_engc_mask,             (0x01 << i2c_cr1_engc_position)
        .equ i2c_cr1_engc,                  (i2c_cr1_engc_mask)

        .equ i2c_cr1_nostretch_position,    (0x07)
        .equ i2c_cr1_nostretch_mask,        (0x01 << i2c_cr1_nostretch_position)
        .equ i2c_cr1_nostretch,             (i2c_cr1_nostretch_mask)

        .equ i2c_cr1_start_position,        (0x08)
        .equ i2c_cr1_start_mask,            (0x01 << i2c_cr1_start_position)
        .equ i2c_cr1_start,                 (i2c_cr1_start_mask)

        .equ i2c_cr1_stop_position,         (0x09)
        .equ i2c_cr1_stop_mask,             (0x01 << i2c_cr1_stop_position)
        .equ i2c_cr1_stop,                  (i2c_cr1_stop_mask)

        .equ i2c_cr1_ack_position,          (0x0a)
        .equ i2c_cr1_ack_mask,              (0x01 << i2c_cr1_ack_position)
        .equ i2c_cr1_ack,                   (i2c_cr1_ack_mask)

        .equ i2c_cr1_pos_position,          (0x0b)
        .equ i2c_cr1_pos_mask,              (0x01 << i2c_cr1_pos_position)
        .equ i2c_cr1_pos,                   (i2c_cr1_pos_mask)

        .equ i2c_cr1_pec_position,          (0x0c)
        .equ i2c_cr1_pec_mask,              (0x01 << i2c_cr1_pec_position)
        .equ i2c_cr1_pec,                   (i2c_cr1_pec_mask)

        .equ i2c_cr1_alert_position,        (0x0d)
        .equ i2c_cr1_alert_mask,            (0x01 << i2c_cr1_alert_position)
        .equ i2c_cr1_alert,                 (i2c_cr1_alert_mask)

        .equ i2c_cr1_swrst_position,        (0x0f)
        .equ i2c_cr1_swrst_mask,            (0x01 << i2c_cr1_swrst_position)
        .equ i2c_cr1_swrst,                 (i2c_cr1_swrst_mask)


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C CR2 register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c_cr2_freq_position,         (0x00)
        .equ i2c_cr2_freq_mask,             (0x3f << i2c_cr2_freq_position)
        .equ i2c_cr2_freq,                  (i2c_cr2_freq_mask)
        .equ i2c_cr2_freq_bit0,             (0x01 << i2c_cr2_freq_position)
        .equ i2c_cr2_freq_bit1,             (0x02 << i2c_cr2_freq_position)
        .equ i2c_cr2_freq_bit2,             (0x04 << i2c_cr2_freq_position)
        .equ i2c_cr2_freq_bit3,             (0x08 << i2c_cr2_freq_position)
        .equ i2c_cr2_freq_bit4,             (0x10 << i2c_cr2_freq_position)
        .equ i2c_cr2_freq_bit5,             (0x20 << i2c_cr2_freq_position)

        .equ i2c_cr2_iterren_position,      (0x08)
        .equ i2c_cr2_iterren_mask,          (0x01 << i2c_cr2_iterren_position)
        .equ i2c_cr2_iterren,               (i2c_cr2_iterren_mask)

        .equ i2c_cr2_itevten_position,      (0x09)
        .equ i2c_cr2_itevten_mask,          (0x01 << i2c_cr2_itevten_position)
        .equ i2c_cr2_itevten,               (i2c_cr2_itevten_mask)

        .equ i2c_cr2_itbufen_position,      (0x0a)
        .equ i2c_cr2_itbufen_mask,          (0x01 << i2c_cr2_itbufen_position)
        .equ i2c_cr2_itbufen,               (i2c_cr2_itbufen_mask)

        .equ i2c_cr2_dmaen_position,        (0x0b)
        .equ i2c_cr2_dmaen_mask,            (0x01 << i2c_cr2_dmaen_position)
        .equ i2c_cr2_dmaen,                 (i2c_cr2_dmaen_mask)

        .equ i2c_cr2_last_position,         (0x0c)
        .equ i2c_cr2_last_mask,             (0x01 << i2c_cr2_last_position)
        .equ i2c_cr2_last,                  (i2c_cr2_last_mask)


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C OAR1 register fields -----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c_oar1_add0_position,        (0x00)
        .equ i2c_oar1_add0_mask,            (0x01 << i2c_oar1_add0_position)
        .equ i2c_oar1_add0,                 (i2c_oar1_add0_mask)

        .equ i2c_oar1_add_position,         (0x01)
        .equ i2c_oar1_add_mask,             (0x01ff << i2c_oar1_add_position)
        .equ i2c_oar1_add,                  (i2c_oar1_add_mask)
        .equ i2c_oar1_add_bit0,             (0x0001 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit1,             (0x0002 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit2,             (0x0004 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit3,             (0x0008 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit4,             (0x0010 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit5,             (0x0020 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit6,             (0x0040 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit7,             (0x0080 << i2c_oar1_add_position)
        .equ i2c_oar1_add_bit8,             (0x0100 << i2c_oar1_add_position)

        .equ i2c_oar1_addmode_position,     (0x0f)
        .equ i2c_oar1_addmode_mask,         (0x01 << i2c_oar1_addmode_position)
        .equ i2c_oar1_addmode,              (i2c_oar1_addmode_mask)


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C OAR2 register fields -----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c_oar2_endual_position,      (0x00)
        .equ i2c_oar2_endual_mask,          (0x01 << i2c_oar2_endual_position)
        .equ i2c_oar2_endual,               (i2c_oar2_endual_mask)

        .equ i2c_oar2_add2_position,        (0x01)
        .equ i2c_oar2_add2_mask,            (0x7f << i2c_oar2_add2_position)
        .equ i2c_oar2_add2,                 (i2c_oar2_add2_mask)
        .equ i2c_oar2_add2_bit0,            (0x01 << i2c_oar2_add2_position)
        .equ i2c_oar2_add2_bit1,            (0x02 << i2c_oar2_add2_position)
        .equ i2c_oar2_add2_bit2,            (0x04 << i2c_oar2_add2_position)
        .equ i2c_oar2_add2_bit3,            (0x08 << i2c_oar2_add2_position)
        .equ i2c_oar2_add2_bit4,            (0x10 << i2c_oar2_add2_position)
        .equ i2c_oar2_add2_bit5,            (0x20 << i2c_oar2_add2_position)
        .equ i2c_oar2_add2_bit6,            (0x40 << i2c_oar2_add2_position)


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C DR register fields -------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c_dr_dr_position,            (0x00)
        .equ i2c_dr_dr_mask,                (0xff << i2c_dr_dr_position)
        .equ i2c_dr_dr,                     (i2c_dr_dr_mask)
        .equ i2c_dr_dr_bit0,                (0x01 << i2c_dr_dr_position)
        .equ i2c_dr_dr_bit1,                (0x02 << i2c_dr_dr_position)
        .equ i2c_dr_dr_bit2,                (0x04 << i2c_dr_dr_position)
        .equ i2c_dr_dr_bit3,                (0x08 << i2c_dr_dr_position)
        .equ i2c_dr_dr_bit4,                (0x10 << i2c_dr_dr_position)
        .equ i2c_dr_dr_bit5,                (0x20 << i2c_dr_dr_position)
        .equ i2c_dr_dr_bit6,                (0x40 << i2c_dr_dr_position)
        .equ i2c_dr_dr_bit7,                (0x80 << i2c_dr_dr_position)


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C SR1 register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c_sr1_sb_position,           (0x00)
        .equ i2c_sr1_sb_mask,               (0x01 << i2c_sr1_sb_position)
        .equ i2c_sr1_sb,                    (i2c_sr1_sb_mask)

        .equ i2c_sr1_addr_position,         (0x01)
        .equ i2c_sr1_addr_mask,             (0x01 << i2c_sr1_addr_position)
        .equ i2c_sr1_addr,                  (i2c_sr1_addr_mask)

        .equ i2c_sr1_btf_position,          (0x02)
        .equ i2c_sr1_btf_mask,              (0x01 << i2c_sr1_btf_position)
        .equ i2c_sr1_btf,                   (i2c_sr1_btf_mask)

        .equ i2c_sr1_add10_position,        (0x03)
        .equ i2c_sr1_add10_mask,            (0x01 << i2c_sr1_add10_position)
        .equ i2c_sr1_add10,                 (i2c_sr1_add10_mask)

        .equ i2c_sr1_stopf_position,        (0x04)
        .equ i2c_sr1_stopf_mask,            (0x01 << i2c_sr1_stopf_position)
        .equ i2c_sr1_stopf,                 (i2c_sr1_stopf_mask)

        .equ i2c_sr1_rxne_position,         (0x06)
        .equ i2c_sr1_rxne_mask,             (0x01 << i2c_sr1_rxne_position)
        .equ i2c_sr1_rxne,                  (i2c_sr1_rxne_mask)

        .equ i2c_sr1_txe_position,          (0x07)
        .equ i2c_sr1_txe_mask,              (0x01 << i2c_sr1_txe_position)
        .equ i2c_sr1_txe,                   (i2c_sr1_txe_mask)

        .equ i2c_sr1_berr_position,         (0x08)
        .equ i2c_sr1_berr_mask,             (0x01 << i2c_sr1_berr_position)
        .equ i2c_sr1_berr,                  (i2c_sr1_berr_mask)

        .equ i2c_sr1_arlo_position,         (0x09)
        .equ i2c_sr1_arlo_mask,             (0x01 << i2c_sr1_arlo_position)
        .equ i2c_sr1_arlo,                  (i2c_sr1_arlo_mask)

        .equ i2c_sr1_af_position,           (0x0a)
        .equ i2c_sr1_af_mask,               (0x01 << i2c_sr1_af_position)
        .equ i2c_sr1_af,                    (i2c_sr1_af_mask)

        .equ i2c_sr1_ovr_position,          (0x0b)
        .equ i2c_sr1_ovr_mask,              (0x01 << i2c_sr1_ovr_position)
        .equ i2c_sr1_ovr,                   (i2c_sr1_ovr_mask)

        .equ i2c_sr1_pecerr_position,       (0x0c)
        .equ i2c_sr1_pecerr_mask,           (0x01 << i2c_sr1_pecerr_position)
        .equ i2c_sr1_pecerr,                (i2c_sr1_pecerr_mask)

        .equ i2c_sr1_timeout_position,      (0x0e)
        .equ i2c_sr1_timeout_mask,          (0x01 << i2c_sr1_timeout_position)
        .equ i2c_sr1_timeout,               (i2c_sr1_timeout_mask)

        .equ i2c_sr1_smbalert_position,     (0x0f)
        .equ i2c_sr1_smbalert_mask,         (0x01 << i2c_sr1_smbalert_position)
        .equ i2c_sr1_smbalert,              (i2c_sr1_smbalert_mask)


@-----------------------------------------------------------------------------------------------@
