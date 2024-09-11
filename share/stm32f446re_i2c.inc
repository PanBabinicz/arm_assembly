        .syntax unified
        .cpu cortex-m4
        .thumb


@-----------------------------------------------------------------------------------------------@
@---------------------------------- I2C registers offsets --------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ i2c1_base,             (0x40005400)    @ I2C1 register boundary address
        .equ i2c2_base,             (0x40005800)    @ I2C2 register boundary address
        .equ i2c3_base,             (0x40005c00)    @ I2C3 register boundary address

        .equ i2c_cr1_offset         (0x00)          @ I2C control register 1 offset
        .equ i2c_cr2_offset         (0x04)          @ I2C control register 2 offset
        .equ i2c_oar1_offset        (0x08)          @ I2C own address register 1 offset
        .equ i2c_oar2_offset        (0x0c)          @ I2C own address register 2 offset
        .equ i2c_dr_offset          (0x10)          @ I2C data register offset
        .equ i2c_sr1_offset         (0x14)          @ I2C status register 1 offset
        .equ i2c_sr2_offset         (0x18)          @ I2C status register 2 offset
        .equ i2c_ccr_offset         (0x1c)          @ I2C clock control register offset
        .equ i2c_trise_offset       (0x20)          @ I2C TRISE register offset
        .equ i2c_fltr_offset        (0x24)          @ I2C FLTR register offset


@-----------------------------------------------------------------------------------------------@
