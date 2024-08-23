    .syntax unified
    .cpu cortex-m4
    .thumb


    @-------------------------------------------------------------------------------------------@
    @---------------------------------- RCC registers offsets ----------------------------------@
    @-------------------------------------------------------------------------------------------@


    .equ rcc_ahb1enr_base,      (0x40023830)    @ RCC register boundary address

    .equ rcc_cr_offset,         (0x00)          @ RCC Clock control register
    .equ rcc_pllcfgr_offset,    (0x04)          @ RCC PLL configuration register
    .equ rcc_cfgr_offset,       (0x08)          @ RCC Clock configuration register
    .equ rcc_cir_offset,        (0x0c)          @ RCC Clock interrupt register

    .equ rcc_ahb1rstr_offset,   (0x10)          @ RCC AHB1 peripheral reset register
    .equ rcc_ahb2rstr_offset,   (0x14)          @ RCC AHB2 peripheral reset register
    .equ rcc_ahb3rstr_offset,   (0x18)          @ RCC AHB3 peripheral reset register

    .equ rcc_apb1rstr_offset,   (0x20)          @ RCC APB1 peripheral reset register
    .equ rcc_apb2rstr_offset,   (0x24)          @ RCC APB2 peripheral reset register

    .equ rcc_ahb1enr_offset,    (0x30)          @ RCC AHB1 peripheral clock enable register
    .equ rcc_ahb2enr_offset,    (0x34)          @ RCC AHB2 peripheral clock enable register
    .equ rcc_ahb3enr_offset,    (0x38)          @ RCC AHB3 peripheral clock enable register

    .equ rcc_apb1enr_offset,    (0x40)          @ RCC APB1 peripheral clock enable register
    .equ rcc_apb2enr_offset,    (0x44)          @ RCC APB2 peripheral clock enable register

    .equ rcc_ahb1lpenr_offset,  (0x50)          @ RCC AHB1 peripheral clock enable in low
                                                @ power mode register

    .equ rcc_ahb2lpenr_offset,  (0x54)          @ RCC AHB2 peripheral clock enable in low
                                                @ power mode register

    .equ rcc_ahb3lpenr_offset,  (0x58)          @ RCC AHB3 peripheral clock enable in low
                                                @ power mode register

    .equ rcc_apb1lpenr_offset,  (0x60)          @ RCC APB1 peripheral clock enable in low
                                                @ power mode register

    .equ rcc_apb2lpenr_offset,  (0x64)          @ RCC APB2 peripheral clock enable in low
                                                @ power mode register

    .equ rcc_bdcr_offset,       (0x70)          @ RCC Backup domain control register
    .equ rcc_csr_offset,        (0x74)          @ RCC Clock control & status register

    .equ rcc_sscgr_offset,      (0x80)          @ RCC Spread specturm clock generation register
    .equ rcc_plli2scfgr_offset, (0x84)          @ RCC PLLI2S configuration register
    .equ rcc_pllsaicfgr_offset, (0x88)          @ RCC PLL configuration register
    .equ rcc_dckcfgr_offset,    (0x8c)          @ RCC Dedicated clock configuration register

    .equ rcc_ckgatenr_offset,   (0x90)          @ RCC clocks gated enable register
    .equ rcc_dckcfgr2_offset,   (0x94)          @ RCC Dedicated clocks configuration register 2
    

    @-------------------------------------------------------------------------------------------@
    @---------------------------------- RCC registers fields -----------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_cr_hsion_position,     (0x00)
    .equ rcc_cr_hsion_mask,         (1 << rcc_cr_hsion_position)

    .equ rcc_cr_hsirdy_position,    (0x01)
    .equ rcc_cr_hsirdy_mask,        (1 << rcc_cr_hsirdy_position)

    .equ rcc_cr_hsitrim_position,   (0x03)
    .equ rcc_cr_hsitrim_mask,       (0x1f << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit0,       (0x01 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit1,       (0x02 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit2,       (0x04 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit3,       (0x08 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit4,       (0x10 << rcc_cr_hsitrim_position)

    TODO:
    rcc_ahb1enr_gpioaen = 0x01
    rcc_ahb1enr_gpioaen = 0x01

    gpiox_moder_base = 0x40020000
    gpiox_moder_input_5 = 0x0 << 10
    gpiox_moder_output_5 = 0x1 << 10
    gpiox_moder_af_5 = 0x2 << 10
    gpiox_moder_analog_5 = 0x3 << 10

    gpiox_bsrr_base = 0x40020018
    gpiox_bsrr_bs5 = 0x1 << 5
    gpiox_bsrr_br5 = 0x1 << 21


    @------------------------------------------------------------------------------------------@
