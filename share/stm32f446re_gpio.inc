    .syntax unified
    .cpu cortex-m4
    .thumb


    @-------------------------------------------------------------------------------------------@
    @---------------------------------- GPIO registers offsets ---------------------------------@
    @-------------------------------------------------------------------------------------------@

    .equ gpioa_moder_base,      (0x40020000)    @ GPIOA register boundary address
    .equ gpiob_moder_base,      (0x40020400)    @ GPIOB register boundary address
    .equ gpioc_moder_base,      (0x40020800)    @ GPIOC register boundary address
    .equ gpiod_moder_base,      (0x40020c00)    @ GPIOD register boundary address
    .equ gpioe_moder_base,      (0x40021000)    @ GPIOE register boundary address
    .equ gpiof_moder_base,      (0x40021400)    @ GPIOF register boundary address
    .equ gpiog_moder_base,      (0x40021800)    @ GPIOG register boundary address
    .equ gpioh_moder_base,      (0x40021c00)    @ GPIOH register boundary address

    .equ gpiox_moder_offset,    (0x00)          @ GPIO port mode register
    .equ gpiox_otyper_offset,   (0x04)          @ GPIO port output type register
    .equ gpiox_ospeedr_offset,  (0x08)          @ GPIO port output speed register
    .equ gpiox_pupdr_offset,    (0x0c)          @ GPIO port pull-up/pull-down register
    .equ gpiox_idr_offset,      (0x10)          @ GPIO port input data register
    .equ gpiox_odr_offset,      (0x14)          @ GPIO port output data register
    .equ gpiox_bsrr_offset,     (0x18)          @ GPIO port bit set/reset register
    .equ gpiox_lckr_offset,     (0x1c)          @ GPIO port configuration lock register
    .equ gpiox_afrlr_offset,    (0x20)          @ GPIO port alternate function low register
    .equ gpiox_afrhr_offset,    (0x24)          @ GPIO port alternate function high register


    @-------------------------------------------------------------------------------------------@
    @------------------------------- GPIOx MODER register fields -------------------------------@
    @-------------------------------------------------------------------------------------------@



    @------------------------------------------------------------------------------------------@
