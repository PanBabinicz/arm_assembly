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
    @---------------------------------- RCC CR register fields ---------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_cr_hsion_position,             (0x00)
    .equ rcc_cr_hsion_mask,                 (0x01 << rcc_cr_hsion_position)
    .equ rcc_cr_hsion,                      (rcc_cr_hsion_mask)

    .equ rcc_cr_hsirdy_position,            (0x01)
    .equ rcc_cr_hsirdy_mask,                (0x01 << rcc_cr_hsirdy_position)
    .equ rcc_cr_hsirdy,                     (rcc_cr_hsirdy_mask)

    .equ rcc_cr_hsitrim_position,           (0x03)
    .equ rcc_cr_hsitrim_mask,               (0x1f << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim,                    (rcc_cr_hsitrim_mask)
    .equ rcc_cr_hsitrim_bit0,               (0x01 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit1,               (0x02 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit2,               (0x04 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit3,               (0x08 << rcc_cr_hsitrim_position)
    .equ rcc_cr_hsitrim_bit4,               (0x10 << rcc_cr_hsitrim_position)

    .equ rcc_cr_hsical_position,            (0x08)
    .equ rcc_cr_hsical_mask,                (0xff << rcc_cr_hsical_position)
    .equ rcc_cr_hsical,                     (rcc_cr_hsical_mask)
    .equ rcc_cr_hsical_bit0,                (0x01 << rcc_cr_hsical_position)
    .equ rcc_cr_hsical_bit1,                (0x02 << rcc_cr_hsical_position)
    .equ rcc_cr_hsical_bit2,                (0x04 << rcc_cr_hsical_position)
    .equ rcc_cr_hsical_bit3,                (0x08 << rcc_cr_hsical_position)
    .equ rcc_cr_hsical_bit4,                (0x10 << rcc_cr_hsical_position)
    .equ rcc_cr_hsical_bit5,                (0x20 << rcc_cr_hsical_position)
    .equ rcc_cr_hsical_bit6,                (0x40 << rcc_cr_hsical_position)
    .equ rcc_cr_hsical_bit7,                (0x80 << rcc_cr_hsical_position)

    .equ rcc_cr_hseon_position,             (0x10)
    .equ rcc_cr_hseon_mask,                 (0x01 << rcc_cr_hseon_position)
    .equ rcc_cr_hseon,                      (rcc_cr_hseon_mask)

    .equ rcc_cr_hserdy_position,            (0x11)
    .equ rcc_cr_hserdy_mask,                (0x01 << rcc_cr_hserdy_position)
    .equ rcc_cr_hserdy,                     (rcc_cr_hserdy_mask)

    .equ rcc_cr_hsebyp_position,            (0x12)
    .equ rcc_cr_hsebyp_mask,                (0x01 << rcc_cr_hsebyp_position)
    .equ rcc_cr_hsebyp,                     (rcc_cr_hsebyp_mask)

    .equ rcc_cr_csson_position,             (0x13)
    .equ rcc_cr_csson_mask,                 (0x01 << rcc_cr_csson_position)
    .equ rcc_cr_csson,                      (rcc_cr_csson_mask)

    .equ rcc_cr_pllon_position,             (0x18)
    .equ rcc_cr_pllon_mask,                 (0x01 << rcc_cr_pllon_position)
    .equ rcc_cr_pllon,                      (rcc_cr_pllon_mask)

    .equ rcc_cr_pllrdy_position,            (0x19)
    .equ rcc_cr_pllrdy_mask,                (0x01 << rcc_cr_pllrdy_position)
    .equ rcc_cr_pllrdy,                     (rcc_cr_pllrdy_mask)

    .equ rcc_cr_plli2son_position,          (0x1a)
    .equ rcc_cr_plli2son_mask,              (0x01 << rcc_cr_plli2son_position)
    .equ rcc_cr_plli2son,                   (rcc_cr_plli2son_mask)

    .equ rcc_cr_plli2srdy_position,         (0x1b)
    .equ rcc_cr_plli2srdy_mask,             (0x01 << rcc_cr_plli2srdy_position)
    .equ rcc_cr_plli2srdy,                  (rcc_cr_plli2srdy_mask)

    .equ rcc_cr_pllsaion_position,          (0x1c)
    .equ rcc_cr_pllsaion_mask,              (0x01 << rcc_cr_pllsaion_position)
    .equ rcc_cr_pllsaion,                   (rcc_cr_pllsaion_mask)

    .equ rcc_cr_pllsairdy_position,         (0x1d)
    .equ rcc_cr_pllsairdy_mask,             (0x01 << rcc_cr_pllsairdy_position)
    .equ rcc_cr_pllsairdy,                  (rcc_cr_pllsairdy_mask)


    @-------------------------------------------------------------------------------------------@
    @------------------------------- RCC AHB1RST register fields -------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_ahb1rstr_gpioarst_position,    (0x00)
    .equ rcc_ahb1rstr_gpioarst_mask,        (0x01 << rcc_ahb1rstr_gpioarst_position)
    .equ rcc_ahb1rstr_gpioarst,             (rcc_ahb1rstr_gpioarst_mask)

    .equ rcc_ahb1rstr_gpiobrst_position,    (0x01)
    .equ rcc_ahb1rstr_gpiobrst_mask,        (0x01 << rcc_ahb1rstr_gpiobrst_position)
    .equ rcc_ahb1rstr_gpiobrst,             (rcc_ahb1rstr_gpiobrst_mask)

    .equ rcc_ahb1rstr_gpiocrst_position,    (0x02)
    .equ rcc_ahb1rstr_gpiocrst_mask,        (0x01 << rcc_ahb1rstr_gpiocrst_position)
    .equ rcc_ahb1rstr_gpiocrst,             (rcc_ahb1rstr_gpiocrst_mask)

    .equ rcc_ahb1rstr_gpiodrst_position,    (0x03)
    .equ rcc_ahb1rstr_gpiodrst_mask,        (0x01 << rcc_ahb1rstr_gpiodrst_position)
    .equ rcc_ahb1rstr_gpiodrst,             (rcc_ahb1rstr_gpiodrst_mask)

    .equ rcc_ahb1rstr_gpioerst_position,    (0x04)
    .equ rcc_ahb1rstr_gpioerst_mask,        (0x01 << rcc_ahb1rstr_gpioerst_position)
    .equ rcc_ahb1rstr_gpioerst,             (rcc_ahb1rstr_gpioerst_mask)

    .equ rcc_ahb1rstr_gpiofrst_position,    (0x05)
    .equ rcc_ahb1rstr_gpiofrst_mask,        (0x01 << rcc_ahb1rstr_gpiofrst_position)
    .equ rcc_ahb1rstr_gpiofrst,             (rcc_ahb1rstr_gpiofrst_mask)

    .equ rcc_ahb1rstr_gpiogrst_position,    (0x06)
    .equ rcc_ahb1rstr_gpiogrst_mask,        (0x01 << rcc_ahb1rstr_gpiogrst_position)
    .equ rcc_ahb1rstr_gpiogrst,             (rcc_ahb1rstr_gpiogrst_mask)

    .equ rcc_ahb1rstr_gpiohrst_position,    (0x07)
    .equ rcc_ahb1rstr_gpiohrst_mask,        (0x01 << rcc_ahb1rstr_gpiohrst_position)
    .equ rcc_ahb1rstr_gpiohrst,             (rcc_ahb1rstr_gpiohrst_mask)

    .equ rcc_ahb1rstr_crcrst_position,      (0x0c)
    .equ rcc_ahb1rstr_crcrst_mask,          (0x01 << rcc_ahb1rstr_crcrst_position)
    .equ rcc_ahb1rstr_crcrst,               (rcc_ahb1rstr_crcrst_mask)

    .equ rcc_ahb1rstr_dma1rst_position,     (0x15)
    .equ rcc_ahb1rstr_dma1rst_mask,         (0x01 << rcc_ahb1rstr_dma1rst_position)
    .equ rcc_ahb1rstr_dma1rst,              (rcc_ahb1rstr_dma1rst_mask)

    .equ rcc_ahb1rstr_dma2rst_position,     (0x16)
    .equ rcc_ahb1rstr_dma2rst_mask,         (0x01 << rcc_ahb1rstr_dma2rst_position)
    .equ rcc_ahb1rstr_dma2rst,              (rcc_ahb1rstr_dma2rst_mask)

    .equ rcc_ahb1rstr_otghsrst_position,    (0x1d)
    .equ rcc_ahb1rstr_otghsrst_mask,        (0x01 << rcc_ahb1rstr_otghsrst_position)
    .equ rcc_ahb1rstr_otghsrst,             (rcc_ahb1rstr_otghsrst_mask)


    @-------------------------------------------------------------------------------------------@
    @------------------------------- RCC AHB2RST register fields -------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_ahb2rstr_dcmirst_position,     (0x00)
    .equ rcc_ahb2rstr_dcmirst_mask,         (0x01 << rcc_ahb2rstr_dcmirst_position)
    .equ rcc_ahb2rstr_dcmirst,              (rcc_ahb2rstr_dcmirst_mask)

    .equ rcc_ahb2rstr_otgfsrst_position,    (0x07)
    .equ rcc_ahb2rstr_otgfsrst_mask,        (0x01 << rcc_ahb2rstr_otgfsrst_position)
    .equ rcc_ahb2rstr_otgfsrst,             (rcc_ahb2rstr_otgfsrst_mask)


    @-------------------------------------------------------------------------------------------@
    @------------------------------- RCC AHB3RST register fields -------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_ahb3rstr_fmcrst_position,      (0x00)
    .equ rcc_ahb3rstr_fmcrst_mask,          (0x01 << rcc_ahb3rstr_fmcrst_position)
    .equ rcc_ahb3rstr_fmcrst,               (rcc_ahb3rstr_fmcrst_mask)

    .equ rcc_ahb3rstr_qspirst_position,     (0x01)
    .equ rcc_ahb3rstr_qspirst_mask,         (0x01 << rcc_ahb3rstr_qspirst_position)
    .equ rcc_ahb3rstr_qspirst,              (rcc_ahb3rstr_qspirst_mask)


    @-------------------------------------------------------------------------------------------@
    @------------------------------- RCC AHB1EN register fields --------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_ahb1enr_gpioaen_position,      (0x00)
    .equ rcc_ahb1enr_gpioaen_mask,          (0x01 << rcc_ahb1enr_gpioaen_position)
    .equ rcc_ahb1enr_gpioaen,               (rcc_ahb1enr_gpioaen_mask)

    .equ rcc_ahb1enr_gpioben_position,      (0x01)
    .equ rcc_ahb1enr_gpioben_mask,          (0x01 << rcc_ahb1enr_gpioben_position)
    .equ rcc_ahb1enr_gpioben,               (rcc_ahb1enr_gpioben_mask)

    .equ rcc_ahb1enr_gpiocen_position,      (0x02)
    .equ rcc_ahb1enr_gpiocen_mask,          (0x01 << rcc_ahb1enr_gpiocen_position)
    .equ rcc_ahb1enr_gpiocen,               (rcc_ahb1enr_gpiocen_mask)

    .equ rcc_ahb1enr_gpioden_position,      (0x03)
    .equ rcc_ahb1enr_gpioden_mask,          (0x01 << rcc_ahb1enr_gpioden_position)
    .equ rcc_ahb1enr_gpioden,               (rcc_ahb1enr_gpioden_mask)

    .equ rcc_ahb1enr_gpioeen_position,      (0x04)
    .equ rcc_ahb1enr_gpioeen_mask,          (0x01 << rcc_ahb1enr_gpioeen_position)
    .equ rcc_ahb1enr_gpioeen,               (rcc_ahb1enr_gpioeen_mask)

    .equ rcc_ahb1enr_gpiofen_position,      (0x05)
    .equ rcc_ahb1enr_gpiofen_mask,          (0x01 << rcc_ahb1enr_gpiofen_position)
    .equ rcc_ahb1enr_gpiofen,               (rcc_ahb1enr_gpiofen_mask)

    .equ rcc_ahb1enr_gpiogen_position,      (0x06)
    .equ rcc_ahb1enr_gpiogen_mask,          (0x01 << rcc_ahb1enr_gpiogen_position)
    .equ rcc_ahb1enr_gpiogen,               (rcc_ahb1enr_gpiogen_mask)

    .equ rcc_ahb1enr_gpiohen_position,      (0x07)
    .equ rcc_ahb1enr_gpiohen_mask,          (0x01 << rcc_ahb1enr_gpiohen_position)
    .equ rcc_ahb1enr_gpiohen,               (rcc_ahb1enr_gpiohen_mask)

    .equ rcc_ahb1enr_crcen_position,        (0x0c)
    .equ rcc_ahb1enr_crcen_mask,            (0x01 << rcc_ahb1enr_crcen_position)
    .equ rcc_ahb1enr_crcen,                 (rcc_ahb1enr_crcen_mask)

    .equ rcc_ahb1enr_bkpsramen_position,    (0x12)
    .equ rcc_ahb1enr_bkpsramen_mask,        (0x01 << rcc_ahb1enr_bkpsramen_position)
    .equ rcc_ahb1enr_bkpsramen,             (rcc_ahb1enr_bkpsramen_mask)

    .equ rcc_ahb1enr_dma1en_position,       (0x15)
    .equ rcc_ahb1enr_dma1en_mask,           (0x01 << rcc_ahb1enr_dma1en_position)
    .equ rcc_ahb1enr_dma1en,                (rcc_ahb1enr_dma1en_mask)

    .equ rcc_ahb1enr_dma2en_position,       (0x16)
    .equ rcc_ahb1enr_dma2en_mask,           (0x01 << rcc_ahb1enr_dma2en_position)
    .equ rcc_ahb1enr_dma2en,                (rcc_ahb1enr_dma2en_mask)

    .equ rcc_ahb1enr_otghsen_position,      (0x1d)
    .equ rcc_ahb1enr_otghsen_mask,          (0x01 << rcc_ahb1enr_otghsen_position)
    .equ rcc_ahb1enr_otghsen,               (rcc_ahb1enr_otghsen_mask)

    .equ rcc_ahb1enr_otghsulpien_position,  (0x1e)
    .equ rcc_ahb1enr_otghsulpien_mask,      (0x01 << rcc_ahb1enr_otghsulpien_position)
    .equ rcc_ahb1enr_otghsulpien,           (rcc_ahb1enr_otghsulpien_mask)


    @-------------------------------------------------------------------------------------------@
    @------------------------------- RCC AHB2EN register fields --------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_ahb2enr_dcmien_position,       (0x00)
    .equ rcc_ahb2enr_dcmien_mask,           (0x01 << rcc_ahb2enr_dcmien_position)
    .equ rcc_ahb2enr_dcmien,                (rcc_ahb2enr_dcmien_mask)

    .equ rcc_ahb2enr_otgfsen_position,      (0x07)
    .equ rcc_ahb2enr_otgfsen_mask,          (0x01 << rcc_ahb2enr_otgfsen_position)
    .equ rcc_ahb2enr_otgfsen,               (rcc_ahb2enr_otgfsen_mask)


    @-------------------------------------------------------------------------------------------@
    @------------------------------- RCC AHB3EN register fields --------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ rcc_ahb3enr_fmcen_position,        (0x00)
    .equ rcc_ahb3enr_fmcen_mask,            (0x01 << rcc_ahb3enr_fmcen_position)
    .equ rcc_ahb3enr_fmcen,                 (rcc_ahb3enr_fmcen_mask)

    .equ rcc_ahb3enr_qspien_position,       (0x01)
    .equ rcc_ahb3enr_qspien_mask,           (0x01 << rcc_ahb3enr_qspien_position)
    .equ rcc_ahb3enr_qspien,                (rcc_ahb3enr_qspien_mask)


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
