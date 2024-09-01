        .syntax unified
        .cpu cortex-m4
        .thumb


@-----------------------------------------------------------------------------------------------@
@------------------------------------ GPIO registers offsets -----------------------------------@
@-----------------------------------------------------------------------------------------------@

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
        .equ gpiox_afrl_offset,     (0x20)          @ GPIO port alternate function low register
        .equ gpiox_afrh_offset,     (0x24)          @ GPIO port alternate function high register


@-----------------------------------------------------------------------------------------------@
@--------------------------------- GPIOx MODER register fields ---------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_moder_moder0_position,       (0x00)
        .equ gpiox_moder_moder0_mask,           (0x03 << gpiox_moder_moder0_position)
        .equ gpiox_moder_moder0,                (gpiox_moder_moder0_mask)
        .equ gpiox_moder_moder0_bit0,           (0x01 << gpiox_moder_moder0_position)
        .equ gpiox_moder_moder0_bit1,           (0x02 << gpiox_moder_moder0_position)

        .equ gpiox_moder_moder1_position,       (0x02)
        .equ gpiox_moder_moder1_mask,           (0x03 << gpiox_moder_moder1_position)
        .equ gpiox_moder_moder1,                (gpiox_moder_moder1_mask)
        .equ gpiox_moder_moder1_bit0,           (0x01 << gpiox_moder_moder1_position)
        .equ gpiox_moder_moder1_bit1,           (0x02 << gpiox_moder_moder1_position)

        .equ gpiox_moder_moder2_position,       (0x04)
        .equ gpiox_moder_moder2_mask,           (0x03 << gpiox_moder_moder2_position)
        .equ gpiox_moder_moder2,                (gpiox_moder_moder2_mask)
        .equ gpiox_moder_moder2_bit0,           (0x01 << gpiox_moder_moder2_position)
        .equ gpiox_moder_moder2_bit1,           (0x02 << gpiox_moder_moder2_position)

        .equ gpiox_moder_moder3_position,       (0x06)
        .equ gpiox_moder_moder3_mask,           (0x03 << gpiox_moder_moder3_position)
        .equ gpiox_moder_moder3,                (gpiox_moder_moder3_mask)
        .equ gpiox_moder_moder3_bit0,           (0x01 << gpiox_moder_moder3_position)
        .equ gpiox_moder_moder3_bit1,           (0x02 << gpiox_moder_moder3_position)

        .equ gpiox_moder_moder4_position,       (0x08)
        .equ gpiox_moder_moder4_mask,           (0x03 << gpiox_moder_moder4_position)
        .equ gpiox_moder_moder4,                (gpiox_moder_moder4_mask)
        .equ gpiox_moder_moder4_bit0,           (0x01 << gpiox_moder_moder4_position)
        .equ gpiox_moder_moder4_bit1,           (0x02 << gpiox_moder_moder4_position)

        .equ gpiox_moder_moder5_position,       (0x0a)
        .equ gpiox_moder_moder5_mask,           (0x03 << gpiox_moder_moder5_position)
        .equ gpiox_moder_moder5,                (gpiox_moder_moder5_mask)
        .equ gpiox_moder_moder5_bit0,           (0x01 << gpiox_moder_moder5_position)
        .equ gpiox_moder_moder5_bit1,           (0x02 << gpiox_moder_moder5_position)

        .equ gpiox_moder_moder6_position,       (0x0c)
        .equ gpiox_moder_moder6_mask,           (0x03 << gpiox_moder_moder6_position)
        .equ gpiox_moder_moder6,                (gpiox_moder_moder6_mask)
        .equ gpiox_moder_moder6_bit0,           (0x01 << gpiox_moder_moder6_position)
        .equ gpiox_moder_moder6_bit1,           (0x02 << gpiox_moder_moder6_position)

        .equ gpiox_moder_moder7_position,       (0x0e)
        .equ gpiox_moder_moder7_mask,           (0x03 << gpiox_moder_moder7_position)
        .equ gpiox_moder_moder7,                (gpiox_moder_moder7_mask)
        .equ gpiox_moder_moder7_bit0,           (0x01 << gpiox_moder_moder7_position)
        .equ gpiox_moder_moder7_bit1,           (0x02 << gpiox_moder_moder7_position)

        .equ gpiox_moder_moder8_position,       (0x10)
        .equ gpiox_moder_moder8_mask,           (0x03 << gpiox_moder_moder8_position)
        .equ gpiox_moder_moder8,                (gpiox_moder_moder8_mask)
        .equ gpiox_moder_moder8_bit0,           (0x01 << gpiox_moder_moder8_position)
        .equ gpiox_moder_moder8_bit1,           (0x02 << gpiox_moder_moder8_position)

        .equ gpiox_moder_moder9_position,       (0x12)
        .equ gpiox_moder_moder9_mask,           (0x03 << gpiox_moder_moder9_position)
        .equ gpiox_moder_moder9,                (gpiox_moder_moder9_mask)
        .equ gpiox_moder_moder9_bit0,           (0x01 << gpiox_moder_moder9_position)
        .equ gpiox_moder_moder9_bit1,           (0x02 << gpiox_moder_moder9_position)

        .equ gpiox_moder_moder10_position,      (0x14)
        .equ gpiox_moder_moder10_mask,          (0x03 << gpiox_moder_moder10_position)
        .equ gpiox_moder_moder10,               (gpiox_moder_moder10_mask)
        .equ gpiox_moder_moder10_bit0,          (0x01 << gpiox_moder_moder10_position)
        .equ gpiox_moder_moder10_bit1,          (0x02 << gpiox_moder_moder10_position)

        .equ gpiox_moder_moder11_position,      (0x16)
        .equ gpiox_moder_moder11_mask,          (0x03 << gpiox_moder_moder11_position)
        .equ gpiox_moder_moder11,               (gpiox_moder_moder11_mask)
        .equ gpiox_moder_moder11_bit0,          (0x01 << gpiox_moder_moder11_position)
        .equ gpiox_moder_moder11_bit1,          (0x02 << gpiox_moder_moder11_position)

        .equ gpiox_moder_moder12_position,      (0x18)
        .equ gpiox_moder_moder12_mask,          (0x03 << gpiox_moder_moder12_position)
        .equ gpiox_moder_moder12,               (gpiox_moder_moder12_mask)
        .equ gpiox_moder_moder12_bit0,          (0x01 << gpiox_moder_moder12_position)
        .equ gpiox_moder_moder12_bit1,          (0x02 << gpiox_moder_moder12_position)

        .equ gpiox_moder_moder13_position,      (0x1a)
        .equ gpiox_moder_moder13_mask,          (0x03 << gpiox_moder_moder13_position)
        .equ gpiox_moder_moder13,               (gpiox_moder_moder13_mask)
        .equ gpiox_moder_moder13_bit0,          (0x01 << gpiox_moder_moder13_position)
        .equ gpiox_moder_moder13_bit1,          (0x02 << gpiox_moder_moder13_position)

        .equ gpiox_moder_moder14_position,      (0x1c)
        .equ gpiox_moder_moder14_mask,          (0x03 << gpiox_moder_moder14_position)
        .equ gpiox_moder_moder14,               (gpiox_moder_moder14_mask)
        .equ gpiox_moder_moder14_bit0,          (0x01 << gpiox_moder_moder14_position)
        .equ gpiox_moder_moder14_bit1,          (0x02 << gpiox_moder_moder14_position)

        .equ gpiox_moder_moder15_position,      (0x1e)
        .equ gpiox_moder_moder15_mask,          (0x03 << gpiox_moder_moder15_position)
        .equ gpiox_moder_moder15,               (gpiox_moder_moder15_mask)
        .equ gpiox_moder_moder15_bit0,          (0x01 << gpiox_moder_moder15_position)
        .equ gpiox_moder_moder15_bit1,          (0x02 << gpiox_moder_moder15_position)


@-----------------------------------------------------------------------------------------------@
@--------------------------------- GPIOx OTYPE register fields ---------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_otyper_ot0_position,         (0x00)
        .equ gpiox_otyper_ot0_mask,             (0x01 << gpiox_otyper_ot0_position)
        .equ gpiox_otyper_ot0,                  (gpiox_otyper_ot0_mask)

        .equ gpiox_otyper_ot1_position,         (0x01)
        .equ gpiox_otyper_ot1_mask,             (0x01 << gpiox_otyper_ot1_position)
        .equ gpiox_otyper_ot1,                  (gpiox_otyper_ot1_mask)

        .equ gpiox_otyper_ot2_position,         (0x02)
        .equ gpiox_otyper_ot2_mask,             (0x01 << gpiox_otyper_ot2_position)
        .equ gpiox_otyper_ot2,                  (gpiox_otyper_ot2_mask)

        .equ gpiox_otyper_ot3_position,         (0x03)
        .equ gpiox_otyper_ot3_mask,             (0x01 << gpiox_otyper_ot3_position)
        .equ gpiox_otyper_ot3,                  (gpiox_otyper_ot3_mask)

        .equ gpiox_otyper_ot4_position,         (0x04)
        .equ gpiox_otyper_ot4_mask,             (0x01 << gpiox_otyper_ot4_position)
        .equ gpiox_otyper_ot4,                  (gpiox_otyper_ot4_mask)

        .equ gpiox_otyper_ot5_position,         (0x05)
        .equ gpiox_otyper_ot5_mask,             (0x01 << gpiox_otyper_ot5_position)
        .equ gpiox_otyper_ot5,                  (gpiox_otyper_ot5_mask)

        .equ gpiox_otyper_ot6_position,         (0x06)
        .equ gpiox_otyper_ot6_mask,             (0x01 << gpiox_otyper_ot6_position)
        .equ gpiox_otyper_ot6,                  (gpiox_otyper_ot6_mask)

        .equ gpiox_otyper_ot7_position,         (0x07)
        .equ gpiox_otyper_ot7_mask,             (0x01 << gpiox_otyper_ot7_position)
        .equ gpiox_otyper_ot7,                  (gpiox_otyper_ot7_mask)

        .equ gpiox_otyper_ot8_position,         (0x08)
        .equ gpiox_otyper_ot8_mask,             (0x01 << gpiox_otyper_ot8_position)
        .equ gpiox_otyper_ot8,                  (gpiox_otyper_ot8_mask)

        .equ gpiox_otyper_ot9_position,         (0x09)
        .equ gpiox_otyper_ot9_mask,             (0x01 << gpiox_otyper_ot9_position)
        .equ gpiox_otyper_ot9,                  (gpiox_otyper_ot9_mask)

        .equ gpiox_otyper_ot10_position,        (0x0a)
        .equ gpiox_otyper_ot10_mask,            (0x01 << gpiox_otyper_ot10_position)
        .equ gpiox_otyper_ot10,                 (gpiox_otyper_ot10_mask)

        .equ gpiox_otyper_ot11_position,        (0x0b)
        .equ gpiox_otyper_ot11_mask,            (0x01 << gpiox_otyper_ot11_position)
        .equ gpiox_otyper_ot11,                 (gpiox_otyper_ot11_mask)

        .equ gpiox_otyper_ot12_position,        (0x0c)
        .equ gpiox_otyper_ot12_mask,            (0x01 << gpiox_otyper_ot12_position)
        .equ gpiox_otyper_ot12,                 (gpiox_otyper_ot12_mask)

        .equ gpiox_otyper_ot13_position,        (0x0d)
        .equ gpiox_otyper_ot13_mask,            (0x01 << gpiox_otyper_ot13_position)
        .equ gpiox_otyper_ot13,                 (gpiox_otyper_ot13_mask)

        .equ gpiox_otyper_ot14_position,        (0x0e)
        .equ gpiox_otyper_ot14_mask,            (0x01 << gpiox_otyper_ot14_position)
        .equ gpiox_otyper_ot14,                 (gpiox_otyper_ot14_mask)

        .equ gpiox_otyper_ot15_position,        (0x0f)
        .equ gpiox_otyper_ot15_mask,            (0x01 << gpiox_otyper_ot15_position)
        .equ gpiox_otyper_ot15,                 (gpiox_otyper_ot15_mask)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx OSPEEDR register fields --------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_ospeedr_ospeedr0_position,   (0x00)
        .equ gpiox_ospeedr_ospeedr0_mask,       (0x03 << gpiox_ospeedr_ospeedr0_position)
        .equ gpiox_ospeedr_ospeedr0,            (gpiox_ospeedr_ospeedr0_mask)
        .equ gpiox_ospeedr_ospeedr0_bit0,       (0x01 << gpiox_ospeedr_ospeedr0_position)
        .equ gpiox_ospeedr_ospeedr0_bit1,       (0x02 << gpiox_ospeedr_ospeedr0_position)

        .equ gpiox_ospeedr_ospeedr1_position,   (0x02)
        .equ gpiox_ospeedr_ospeedr1_mask,       (0x03 << gpiox_ospeedr_ospeedr1_position)
        .equ gpiox_ospeedr_ospeedr1,            (gpiox_ospeedr_ospeedr1_mask)
        .equ gpiox_ospeedr_ospeedr1_bit0,       (0x01 << gpiox_ospeedr_ospeedr1_position)
        .equ gpiox_ospeedr_ospeedr1_bit1,       (0x02 << gpiox_ospeedr_ospeedr1_position)

        .equ gpiox_ospeedr_ospeedr2_position,   (0x04)
        .equ gpiox_ospeedr_ospeedr2_mask,       (0x03 << gpiox_ospeedr_ospeedr2_position)
        .equ gpiox_ospeedr_ospeedr2,            (gpiox_ospeedr_ospeedr2_mask)
        .equ gpiox_ospeedr_ospeedr2_bit0,       (0x01 << gpiox_ospeedr_ospeedr2_position)
        .equ gpiox_ospeedr_ospeedr2_bit1,       (0x02 << gpiox_ospeedr_ospeedr2_position)

        .equ gpiox_ospeedr_ospeedr3_position,   (0x06)
        .equ gpiox_ospeedr_ospeedr3_mask,       (0x03 << gpiox_ospeedr_ospeedr3_position)
        .equ gpiox_ospeedr_ospeedr3,            (gpiox_ospeedr_ospeedr3_mask)
        .equ gpiox_ospeedr_ospeedr3_bit0,       (0x01 << gpiox_ospeedr_ospeedr3_position)
        .equ gpiox_ospeedr_ospeedr3_bit1,       (0x02 << gpiox_ospeedr_ospeedr3_position)

        .equ gpiox_ospeedr_ospeedr4_position,   (0x08)
        .equ gpiox_ospeedr_ospeedr4_mask,       (0x03 << gpiox_ospeedr_ospeedr4_position)
        .equ gpiox_ospeedr_ospeedr4,            (gpiox_ospeedr_ospeedr4_mask)
        .equ gpiox_ospeedr_ospeedr4_bit0,       (0x01 << gpiox_ospeedr_ospeedr4_position)
        .equ gpiox_ospeedr_ospeedr4_bit1,       (0x02 << gpiox_ospeedr_ospeedr4_position)

        .equ gpiox_ospeedr_ospeedr5_position,   (0x0a)
        .equ gpiox_ospeedr_ospeedr5_mask,       (0x03 << gpiox_ospeedr_ospeedr5_position)
        .equ gpiox_ospeedr_ospeedr5,            (gpiox_ospeedr_ospeedr5_mask)
        .equ gpiox_ospeedr_ospeedr5_bit0,       (0x01 << gpiox_ospeedr_ospeedr5_position)
        .equ gpiox_ospeedr_ospeedr5_bit1,       (0x02 << gpiox_ospeedr_ospeedr5_position)

        .equ gpiox_ospeedr_ospeedr6_position,   (0x0c)
        .equ gpiox_ospeedr_ospeedr6_mask,       (0x03 << gpiox_ospeedr_ospeedr6_position)
        .equ gpiox_ospeedr_ospeedr6,            (gpiox_ospeedr_ospeedr6_mask)
        .equ gpiox_ospeedr_ospeedr6_bit0,       (0x01 << gpiox_ospeedr_ospeedr6_position)
        .equ gpiox_ospeedr_ospeedr6_bit1,       (0x02 << gpiox_ospeedr_ospeedr6_position)

        .equ gpiox_ospeedr_ospeedr7_position,   (0x0e)
        .equ gpiox_ospeedr_ospeedr7_mask,       (0x03 << gpiox_ospeedr_ospeedr7_position)
        .equ gpiox_ospeedr_ospeedr7,            (gpiox_ospeedr_ospeedr7_mask)
        .equ gpiox_ospeedr_ospeedr7_bit0,       (0x01 << gpiox_ospeedr_ospeedr7_position)
        .equ gpiox_ospeedr_ospeedr7_bit1,       (0x02 << gpiox_ospeedr_ospeedr7_position)

        .equ gpiox_ospeedr_ospeedr8_position,   (0x10)
        .equ gpiox_ospeedr_ospeedr8_mask,       (0x03 << gpiox_ospeedr_ospeedr8_position)
        .equ gpiox_ospeedr_ospeedr8,            (gpiox_ospeedr_ospeedr8_mask)
        .equ gpiox_ospeedr_ospeedr8_bit0,       (0x01 << gpiox_ospeedr_ospeedr8_position)
        .equ gpiox_ospeedr_ospeedr8_bit1,       (0x02 << gpiox_ospeedr_ospeedr8_position)

        .equ gpiox_ospeedr_ospeedr9_position,   (0x12)
        .equ gpiox_ospeedr_ospeedr9_mask,       (0x03 << gpiox_ospeedr_ospeedr9_position)
        .equ gpiox_ospeedr_ospeedr9,            (gpiox_ospeedr_ospeedr9_mask)
        .equ gpiox_ospeedr_ospeedr9_bit0,       (0x01 << gpiox_ospeedr_ospeedr9_position)
        .equ gpiox_ospeedr_ospeedr9_bit1,       (0x02 << gpiox_ospeedr_ospeedr9_position)

        .equ gpiox_ospeedr_ospeedr10_position,  (0x14)
        .equ gpiox_ospeedr_ospeedr10_mask,      (0x03 << gpiox_ospeedr_ospeedr10_position)
        .equ gpiox_ospeedr_ospeedr10,           (gpiox_ospeedr_ospeedr10_mask)
        .equ gpiox_ospeedr_ospeedr10_bit0,      (0x01 << gpiox_ospeedr_ospeedr10_position)
        .equ gpiox_ospeedr_ospeedr10_bit1,      (0x02 << gpiox_ospeedr_ospeedr10_position)

        .equ gpiox_ospeedr_ospeedr11_position,  (0x16)
        .equ gpiox_ospeedr_ospeedr11_mask,      (0x03 << gpiox_ospeedr_ospeedr11_position)
        .equ gpiox_ospeedr_ospeedr11,           (gpiox_ospeedr_ospeedr11_mask)
        .equ gpiox_ospeedr_ospeedr11_bit0,      (0x01 << gpiox_ospeedr_ospeedr11_position)
        .equ gpiox_ospeedr_ospeedr11_bit1,      (0x02 << gpiox_ospeedr_ospeedr11_position)

        .equ gpiox_ospeedr_ospeedr12_position,  (0x18)
        .equ gpiox_ospeedr_ospeedr12_mask,      (0x03 << gpiox_ospeedr_ospeedr12_position)
        .equ gpiox_ospeedr_ospeedr12,           (gpiox_ospeedr_ospeedr12_mask)
        .equ gpiox_ospeedr_ospeedr12_bit0,      (0x01 << gpiox_ospeedr_ospeedr12_position)
        .equ gpiox_ospeedr_ospeedr12_bit1,      (0x02 << gpiox_ospeedr_ospeedr12_position)

        .equ gpiox_ospeedr_ospeedr13_position,  (0x1a)
        .equ gpiox_ospeedr_ospeedr13_mask,      (0x03 << gpiox_ospeedr_ospeedr13_position)
        .equ gpiox_ospeedr_ospeedr13,           (gpiox_ospeedr_ospeedr13_mask)
        .equ gpiox_ospeedr_ospeedr13_bit0,      (0x01 << gpiox_ospeedr_ospeedr13_position)
        .equ gpiox_ospeedr_ospeedr13_bit1,      (0x02 << gpiox_ospeedr_ospeedr13_position)

        .equ gpiox_ospeedr_ospeedr14_position,  (0x1c)
        .equ gpiox_ospeedr_ospeedr14_mask,      (0x03 << gpiox_ospeedr_ospeedr14_position)
        .equ gpiox_ospeedr_ospeedr14,           (gpiox_ospeedr_ospeedr14_mask)
        .equ gpiox_ospeedr_ospeedr14_bit0,      (0x01 << gpiox_ospeedr_ospeedr14_position)
        .equ gpiox_ospeedr_ospeedr14_bit1,      (0x02 << gpiox_ospeedr_ospeedr14_position)

        .equ gpiox_ospeedr_ospeedr15_position,  (0x1e)
        .equ gpiox_ospeedr_ospeedr15_mask,      (0x03 << gpiox_ospeedr_ospeedr15_position)
        .equ gpiox_ospeedr_ospeedr15,           (gpiox_ospeedr_ospeedr15_mask)
        .equ gpiox_ospeedr_ospeedr15_bit0,      (0x01 << gpiox_ospeedr_ospeedr15_position)
        .equ gpiox_ospeedr_ospeedr15_bit1,      (0x02 << gpiox_ospeedr_ospeedr15_position)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx PUPDR register fields ----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_pupdr_pupdr0_position,       (0x00)
        .equ gpiox_pupdr_pupdr0_mask,           (0x03 << gpiox_pupdr_pupdr0_position)
        .equ gpiox_pupdr_pupdr0,                (gpiox_pupdr_pupdr0_mask)
        .equ gpiox_pupdr_pupdr0_bit0,           (0x01 << gpiox_pupdr_pupdr0_position)
        .equ gpiox_pupdr_pupdr0_bit1,           (0x02 << gpiox_pupdr_pupdr0_position)

        .equ gpiox_pupdr_pupdr1_position,       (0x02)
        .equ gpiox_pupdr_pupdr1_mask,           (0x03 << gpiox_pupdr_pupdr1_position)
        .equ gpiox_pupdr_pupdr1,                (gpiox_pupdr_pupdr1_mask)
        .equ gpiox_pupdr_pupdr1_bit0,           (0x01 << gpiox_pupdr_pupdr1_position)
        .equ gpiox_pupdr_pupdr1_bit1,           (0x02 << gpiox_pupdr_pupdr1_position)

        .equ gpiox_pupdr_pupdr2_position,       (0x04)
        .equ gpiox_pupdr_pupdr2_mask,           (0x03 << gpiox_pupdr_pupdr2_position)
        .equ gpiox_pupdr_pupdr2,                (gpiox_pupdr_pupdr2_mask)
        .equ gpiox_pupdr_pupdr2_bit0,           (0x01 << gpiox_pupdr_pupdr2_position)
        .equ gpiox_pupdr_pupdr2_bit1,           (0x02 << gpiox_pupdr_pupdr2_position)

        .equ gpiox_pupdr_pupdr3_position,       (0x06)
        .equ gpiox_pupdr_pupdr3_mask,           (0x03 << gpiox_pupdr_pupdr3_position)
        .equ gpiox_pupdr_pupdr3,                (gpiox_pupdr_pupdr3_mask)
        .equ gpiox_pupdr_pupdr3_bit0,           (0x01 << gpiox_pupdr_pupdr3_position)
        .equ gpiox_pupdr_pupdr3_bit1,           (0x02 << gpiox_pupdr_pupdr3_position)

        .equ gpiox_pupdr_pupdr4_position,       (0x08)
        .equ gpiox_pupdr_pupdr4_mask,           (0x03 << gpiox_pupdr_pupdr4_position)
        .equ gpiox_pupdr_pupdr4,                (gpiox_pupdr_pupdr4_mask)
        .equ gpiox_pupdr_pupdr4_bit0,           (0x01 << gpiox_pupdr_pupdr4_position)
        .equ gpiox_pupdr_pupdr4_bit1,           (0x02 << gpiox_pupdr_pupdr4_position)

        .equ gpiox_pupdr_pupdr5_position,       (0x0a)
        .equ gpiox_pupdr_pupdr5_mask,           (0x03 << gpiox_pupdr_pupdr5_position)
        .equ gpiox_pupdr_pupdr5,                (gpiox_pupdr_pupdr5_mask)
        .equ gpiox_pupdr_pupdr5_bit0,           (0x01 << gpiox_pupdr_pupdr5_position)
        .equ gpiox_pupdr_pupdr5_bit1,           (0x02 << gpiox_pupdr_pupdr5_position)

        .equ gpiox_pupdr_pupdr6_position,       (0x0c)
        .equ gpiox_pupdr_pupdr6_mask,           (0x03 << gpiox_pupdr_pupdr6_position)
        .equ gpiox_pupdr_pupdr6,                (gpiox_pupdr_pupdr6_mask)
        .equ gpiox_pupdr_pupdr6_bit0,           (0x01 << gpiox_pupdr_pupdr6_position)
        .equ gpiox_pupdr_pupdr6_bit1,           (0x02 << gpiox_pupdr_pupdr6_position)

        .equ gpiox_pupdr_pupdr7_position,       (0x0e)
        .equ gpiox_pupdr_pupdr7_mask,           (0x03 << gpiox_pupdr_pupdr7_position)
        .equ gpiox_pupdr_pupdr7,                (gpiox_pupdr_pupdr7_mask)
        .equ gpiox_pupdr_pupdr7_bit0,           (0x01 << gpiox_pupdr_pupdr7_position)
        .equ gpiox_pupdr_pupdr7_bit1,           (0x02 << gpiox_pupdr_pupdr7_position)

        .equ gpiox_pupdr_pupdr8_position,       (0x10)
        .equ gpiox_pupdr_pupdr8_mask,           (0x03 << gpiox_pupdr_pupdr8_position)
        .equ gpiox_pupdr_pupdr8,                (gpiox_pupdr_pupdr8_mask)
        .equ gpiox_pupdr_pupdr8_bit0,           (0x01 << gpiox_pupdr_pupdr8_position)
        .equ gpiox_pupdr_pupdr8_bit1,           (0x02 << gpiox_pupdr_pupdr8_position)

        .equ gpiox_pupdr_pupdr9_position,       (0x12)
        .equ gpiox_pupdr_pupdr9_mask,           (0x03 << gpiox_pupdr_pupdr9_position)
        .equ gpiox_pupdr_pupdr9,                (gpiox_pupdr_pupdr9_mask)
        .equ gpiox_pupdr_pupdr9_bit0,           (0x01 << gpiox_pupdr_pupdr9_position)
        .equ gpiox_pupdr_pupdr9_bit1,           (0x02 << gpiox_pupdr_pupdr9_position)

        .equ gpiox_pupdr_pupdr10_position,      (0x14)
        .equ gpiox_pupdr_pupdr10_mask,          (0x03 << gpiox_pupdr_pupdr10_position)
        .equ gpiox_pupdr_pupdr10,               (gpiox_pupdr_pupdr10_mask)
        .equ gpiox_pupdr_pupdr10_bit0,          (0x01 << gpiox_pupdr_pupdr10_position)
        .equ gpiox_pupdr_pupdr10_bit1,          (0x02 << gpiox_pupdr_pupdr10_position)

        .equ gpiox_pupdr_pupdr11_position,      (0x16)
        .equ gpiox_pupdr_pupdr11_mask,          (0x03 << gpiox_pupdr_pupdr11_position)
        .equ gpiox_pupdr_pupdr11,               (gpiox_pupdr_pupdr11_mask)
        .equ gpiox_pupdr_pupdr11_bit0,          (0x01 << gpiox_pupdr_pupdr11_position)
        .equ gpiox_pupdr_pupdr11_bit1,          (0x02 << gpiox_pupdr_pupdr11_position)

        .equ gpiox_pupdr_pupdr12_position,      (0x18)
        .equ gpiox_pupdr_pupdr12_mask,          (0x03 << gpiox_pupdr_pupdr12_position)
        .equ gpiox_pupdr_pupdr12,               (gpiox_pupdr_pupdr12_mask)
        .equ gpiox_pupdr_pupdr12_bit0,          (0x01 << gpiox_pupdr_pupdr12_position)
        .equ gpiox_pupdr_pupdr12_bit1,          (0x02 << gpiox_pupdr_pupdr12_position)

        .equ gpiox_pupdr_pupdr13_position,      (0x1a)
        .equ gpiox_pupdr_pupdr13_mask,          (0x03 << gpiox_pupdr_pupdr13_position)
        .equ gpiox_pupdr_pupdr13,               (gpiox_pupdr_pupdr13_mask)
        .equ gpiox_pupdr_pupdr13_bit0,          (0x01 << gpiox_pupdr_pupdr13_position)
        .equ gpiox_pupdr_pupdr13_bit1,          (0x02 << gpiox_pupdr_pupdr13_position)

        .equ gpiox_pupdr_pupdr14_position,      (0x1c)
        .equ gpiox_pupdr_pupdr14_mask,          (0x03 << gpiox_pupdr_pupdr14_position)
        .equ gpiox_pupdr_pupdr14,               (gpiox_pupdr_pupdr14_mask)
        .equ gpiox_pupdr_pupdr14_bit0,          (0x01 << gpiox_pupdr_pupdr14_position)
        .equ gpiox_pupdr_pupdr14_bit1,          (0x02 << gpiox_pupdr_pupdr14_position)

        .equ gpiox_pupdr_pupdr15_position,      (0x1e)
        .equ gpiox_pupdr_pupdr15_mask,          (0x03 << gpiox_pupdr_pupdr15_position)
        .equ gpiox_pupdr_pupdr15,               (gpiox_pupdr_pupdr15_mask)
        .equ gpiox_pupdr_pupdr15_bit0,          (0x01 << gpiox_pupdr_pupdr15_position)
        .equ gpiox_pupdr_pupdr15_bit1,          (0x02 << gpiox_pupdr_pupdr15_position)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx IDR register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_idr_idr0_position,           (0x00)
        .equ gpiox_idr_idr0_mask,               (0x01 << gpiox_idr_idr0_position)
        .equ gpiox_idr_idr0,                    (gpiox_idr_idr0_mask)

        .equ gpiox_idr_idr1_position,           (0x01)
        .equ gpiox_idr_idr1_mask,               (0x01 << gpiox_idr_idr1_position)
        .equ gpiox_idr_idr1,                    (gpiox_idr_idr1_mask)

        .equ gpiox_idr_idr2_position,           (0x02)
        .equ gpiox_idr_idr2_mask,               (0x01 << gpiox_idr_idr2_position)
        .equ gpiox_idr_idr2,                    (gpiox_idr_idr2_mask)

        .equ gpiox_idr_idr3_position,           (0x03)
        .equ gpiox_idr_idr3_mask,               (0x01 << gpiox_idr_idr3_position)
        .equ gpiox_idr_idr3,                    (gpiox_idr_idr3_mask)

        .equ gpiox_idr_idr4_position,           (0x04)
        .equ gpiox_idr_idr4_mask,               (0x01 << gpiox_idr_idr4_position)
        .equ gpiox_idr_idr4,                    (gpiox_idr_idr4_mask)

        .equ gpiox_idr_idr5_position,           (0x05)
        .equ gpiox_idr_idr5_mask,               (0x01 << gpiox_idr_idr5_position)
        .equ gpiox_idr_idr5,                    (gpiox_idr_idr5_mask)

        .equ gpiox_idr_idr6_position,           (0x06)
        .equ gpiox_idr_idr6_mask,               (0x01 << gpiox_idr_idr6_position)
        .equ gpiox_idr_idr6,                    (gpiox_idr_idr6_mask)

        .equ gpiox_idr_idr7_position,           (0x07)
        .equ gpiox_idr_idr7_mask,               (0x01 << gpiox_idr_idr7_position)
        .equ gpiox_idr_idr7,                    (gpiox_idr_idr7_mask)

        .equ gpiox_idr_idr8_position,           (0x08)
        .equ gpiox_idr_idr8_mask,               (0x01 << gpiox_idr_idr8_position)
        .equ gpiox_idr_idr8,                    (gpiox_idr_idr8_mask)

        .equ gpiox_idr_idr9_position,           (0x09)
        .equ gpiox_idr_idr9_mask,               (0x01 << gpiox_idr_idr9_position)
        .equ gpiox_idr_idr9,                    (gpiox_idr_idr9_mask)

        .equ gpiox_idr_idr10_position,          (0x0a)
        .equ gpiox_idr_idr10_mask,              (0x01 << gpiox_idr_idr10_position)
        .equ gpiox_idr_idr10,                   (gpiox_idr_idr10_mask)

        .equ gpiox_idr_idr11_position,          (0x0b)
        .equ gpiox_idr_idr11_mask,              (0x01 << gpiox_idr_idr11_position)
        .equ gpiox_idr_idr11,                   (gpiox_idr_idr11_mask)

        .equ gpiox_idr_idr12_position,          (0x0c)
        .equ gpiox_idr_idr12_mask,              (0x01 << gpiox_idr_idr12_position)
        .equ gpiox_idr_idr12,                   (gpiox_idr_idr12_mask)

        .equ gpiox_idr_idr13_position,          (0x0d)
        .equ gpiox_idr_idr13_mask,              (0x01 << gpiox_idr_idr13_position)
        .equ gpiox_idr_idr13,                   (gpiox_idr_idr13_mask)

        .equ gpiox_idr_idr14_position,          (0x0e)
        .equ gpiox_idr_idr14_mask,              (0x01 << gpiox_idr_idr14_position)
        .equ gpiox_idr_idr14,                   (gpiox_idr_idr14_mask)

        .equ gpiox_idr_idr15_position,          (0x0f)
        .equ gpiox_idr_idr15_mask,              (0x01 << gpiox_idr_idr15_position)
        .equ gpiox_idr_idr15,                   (gpiox_idr_idr15_mask)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx ODR register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_odr_odr0_position,           (0x00)
        .equ gpiox_odr_odr0_mask,               (0x01 << gpiox_odr_odr0_position)
        .equ gpiox_odr_odr0,                    (gpiox_odr_odr0_mask)

        .equ gpiox_odr_odr1_position,           (0x01)
        .equ gpiox_odr_odr1_mask,               (0x01 << gpiox_odr_odr1_position)
        .equ gpiox_odr_odr1,                    (gpiox_odr_odr1_mask)

        .equ gpiox_odr_odr2_position,           (0x02)
        .equ gpiox_odr_odr2_mask,               (0x01 << gpiox_odr_odr2_position)
        .equ gpiox_odr_odr2,                    (gpiox_odr_odr2_mask)

        .equ gpiox_odr_odr3_position,           (0x03)
        .equ gpiox_odr_odr3_mask,               (0x01 << gpiox_odr_odr3_position)
        .equ gpiox_odr_odr3,                    (gpiox_odr_odr3_mask)

        .equ gpiox_odr_odr4_position,           (0x04)
        .equ gpiox_odr_odr4_mask,               (0x01 << gpiox_odr_odr4_position)
        .equ gpiox_odr_odr4,                    (gpiox_odr_odr4_mask)

        .equ gpiox_odr_odr5_position,           (0x05)
        .equ gpiox_odr_odr5_mask,               (0x01 << gpiox_odr_odr5_position)
        .equ gpiox_odr_odr5,                    (gpiox_odr_odr5_mask)

        .equ gpiox_odr_odr6_position,           (0x06)
        .equ gpiox_odr_odr6_mask,               (0x01 << gpiox_odr_odr6_position)
        .equ gpiox_odr_odr6,                    (gpiox_odr_odr6_mask)

        .equ gpiox_odr_odr7_position,           (0x07)
        .equ gpiox_odr_odr7_mask,               (0x01 << gpiox_odr_odr7_position)
        .equ gpiox_odr_odr7,                    (gpiox_odr_odr7_mask)

        .equ gpiox_odr_odr8_position,           (0x08)
        .equ gpiox_odr_odr8_mask,               (0x01 << gpiox_odr_odr8_position)
        .equ gpiox_odr_odr8,                    (gpiox_odr_odr8_mask)

        .equ gpiox_odr_odr9_position,           (0x09)
        .equ gpiox_odr_odr9_mask,               (0x01 << gpiox_odr_odr9_position)
        .equ gpiox_odr_odr9,                    (gpiox_odr_odr9_mask)

        .equ gpiox_odr_odr10_position,          (0x0a)
        .equ gpiox_odr_odr10_mask,              (0x01 << gpiox_odr_odr10_position)
        .equ gpiox_odr_odr10,                   (gpiox_odr_odr10_mask)

        .equ gpiox_odr_odr11_position,          (0x0b)
        .equ gpiox_odr_odr11_mask,              (0x01 << gpiox_odr_odr11_position)
        .equ gpiox_odr_odr11,                   (gpiox_odr_odr11_mask)

        .equ gpiox_odr_odr12_position,          (0x0c)
        .equ gpiox_odr_odr12_mask,              (0x01 << gpiox_odr_odr12_position)
        .equ gpiox_odr_odr12,                   (gpiox_odr_odr12_mask)

        .equ gpiox_odr_odr13_position,          (0x0d)
        .equ gpiox_odr_odr13_mask,              (0x01 << gpiox_odr_odr13_position)
        .equ gpiox_odr_odr13,                   (gpiox_odr_odr13_mask)

        .equ gpiox_odr_odr14_position,          (0x0e)
        .equ gpiox_odr_odr14_mask,              (0x01 << gpiox_odr_odr14_position)
        .equ gpiox_odr_odr14,                   (gpiox_odr_odr14_mask)

        .equ gpiox_odr_odr15_position,          (0x0f)
        .equ gpiox_odr_odr15_mask,              (0x01 << gpiox_odr_odr15_position)
        .equ gpiox_odr_odr15,                   (gpiox_odr_odr15_mask)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx BSRR register fields -----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_bsrr_bs0_position,           (0x00)
        .equ gpiox_bsrr_bs0_mask,               (0x01 << gpiox_bsrr_bs0_position)
        .equ gpiox_bsrr_bs0,                    (gpiox_bsrr_bs0_mask)

        .equ gpiox_bsrr_bs1_position,           (0x01)
        .equ gpiox_bsrr_bs1_mask,               (0x01 << gpiox_bsrr_bs1_position)
        .equ gpiox_bsrr_bs1,                    (gpiox_bsrr_bs1_mask)

        .equ gpiox_bsrr_bs2_position,           (0x02)
        .equ gpiox_bsrr_bs2_mask,               (0x01 << gpiox_bsrr_bs2_position)
        .equ gpiox_bsrr_bs2,                    (gpiox_bsrr_bs2_mask)

        .equ gpiox_bsrr_bs3_position,           (0x03)
        .equ gpiox_bsrr_bs3_mask,               (0x01 << gpiox_bsrr_bs3_position)
        .equ gpiox_bsrr_bs3,                    (gpiox_bsrr_bs3_mask)

        .equ gpiox_bsrr_bs4_position,           (0x04)
        .equ gpiox_bsrr_bs4_mask,               (0x01 << gpiox_bsrr_bs4_position)
        .equ gpiox_bsrr_bs4,                    (gpiox_bsrr_bs4_mask)

        .equ gpiox_bsrr_bs5_position,           (0x05)
        .equ gpiox_bsrr_bs5_mask,               (0x01 << gpiox_bsrr_bs5_position)
        .equ gpiox_bsrr_bs5,                    (gpiox_bsrr_bs5_mask)

        .equ gpiox_bsrr_bs6_position,           (0x06)
        .equ gpiox_bsrr_bs6_mask,               (0x01 << gpiox_bsrr_bs6_position)
        .equ gpiox_bsrr_bs6,                    (gpiox_bsrr_bs6_mask)

        .equ gpiox_bsrr_bs7_position,           (0x07)
        .equ gpiox_bsrr_bs7_mask,               (0x01 << gpiox_bsrr_bs7_position)
        .equ gpiox_bsrr_bs7,                    (gpiox_bsrr_bs7_mask)

        .equ gpiox_bsrr_bs8_position,           (0x08)
        .equ gpiox_bsrr_bs8_mask,               (0x01 << gpiox_bsrr_bs8_position)
        .equ gpiox_bsrr_bs8,                    (gpiox_bsrr_bs8_mask)

        .equ gpiox_bsrr_bs9_position,           (0x09)
        .equ gpiox_bsrr_bs9_mask,               (0x01 << gpiox_bsrr_bs9_position)
        .equ gpiox_bsrr_bs9,                    (gpiox_bsrr_bs9_mask)

        .equ gpiox_bsrr_bs10_position,          (0x0a)
        .equ gpiox_bsrr_bs10_mask,              (0x01 << gpiox_bsrr_bs10_position)
        .equ gpiox_bsrr_bs10,                   (gpiox_bsrr_bs10_mask)

        .equ gpiox_bsrr_bs11_position,          (0x0b)
        .equ gpiox_bsrr_bs11_mask,              (0x01 << gpiox_bsrr_bs11_position)
        .equ gpiox_bsrr_bs11,                   (gpiox_bsrr_bs11_mask)

        .equ gpiox_bsrr_bs12_position,          (0x0c)
        .equ gpiox_bsrr_bs12_mask,              (0x01 << gpiox_bsrr_bs12_position)
        .equ gpiox_bsrr_bs12,                   (gpiox_bsrr_bs12_mask)

        .equ gpiox_bsrr_bs13_position,          (0x0d)
        .equ gpiox_bsrr_bs13_mask,              (0x01 << gpiox_bsrr_bs13_position)
        .equ gpiox_bsrr_bs13,                   (gpiox_bsrr_bs13_mask)

        .equ gpiox_bsrr_bs14_position,          (0x0e)
        .equ gpiox_bsrr_bs14_mask,              (0x01 << gpiox_bsrr_bs14_position)
        .equ gpiox_bsrr_bs14,                   (gpiox_bsrr_bs14_mask)

        .equ gpiox_bsrr_bs15_position,          (0x0f)
        .equ gpiox_bsrr_bs15_mask,              (0x01 << gpiox_bsrr_bs15_position)
        .equ gpiox_bsrr_bs15,                   (gpiox_bsrr_bs15_mask)

        .equ gpiox_bsrr_br0_position,           (0x10)
        .equ gpiox_bsrr_br0_mask,               (0x01 << gpiox_bsrr_br0_position)
        .equ gpiox_bsrr_br0,                    (gpiox_bsrr_br0_mask)

        .equ gpiox_bsrr_br1_position,           (0x11)
        .equ gpiox_bsrr_br1_mask,               (0x01 << gpiox_bsrr_br1_position)
        .equ gpiox_bsrr_br1,                    (gpiox_bsrr_br1_mask)

        .equ gpiox_bsrr_br2_position,           (0x12)
        .equ gpiox_bsrr_br2_mask,               (0x01 << gpiox_bsrr_br2_position)
        .equ gpiox_bsrr_br2,                    (gpiox_bsrr_br2_mask)

        .equ gpiox_bsrr_br3_position,           (0x13)
        .equ gpiox_bsrr_br3_mask,               (0x01 << gpiox_bsrr_br3_position)
        .equ gpiox_bsrr_br3,                    (gpiox_bsrr_br3_mask)

        .equ gpiox_bsrr_br4_position,           (0x14)
        .equ gpiox_bsrr_br4_mask,               (0x01 << gpiox_bsrr_br4_position)
        .equ gpiox_bsrr_br4,                    (gpiox_bsrr_br4_mask)

        .equ gpiox_bsrr_br5_position,           (0x15)
        .equ gpiox_bsrr_br5_mask,               (0x01 << gpiox_bsrr_br5_position)
        .equ gpiox_bsrr_br5,                    (gpiox_bsrr_br5_mask)

        .equ gpiox_bsrr_br6_position,           (0x16)
        .equ gpiox_bsrr_br6_mask,               (0x01 << gpiox_bsrr_br6_position)
        .equ gpiox_bsrr_br6,                    (gpiox_bsrr_br6_mask)

        .equ gpiox_bsrr_br7_position,           (0x17)
        .equ gpiox_bsrr_br7_mask,               (0x01 << gpiox_bsrr_br7_position)
        .equ gpiox_bsrr_br7,                    (gpiox_bsrr_br7_mask)

        .equ gpiox_bsrr_br8_position,           (0x18)
        .equ gpiox_bsrr_br8_mask,               (0x01 << gpiox_bsrr_br8_position)
        .equ gpiox_bsrr_br8,                    (gpiox_bsrr_br8_mask)

        .equ gpiox_bsrr_br9_position,           (0x19)
        .equ gpiox_bsrr_br9_mask,               (0x01 << gpiox_bsrr_br9_position)
        .equ gpiox_bsrr_br9,                    (gpiox_bsrr_br9_mask)

        .equ gpiox_bsrr_br10_position,          (0x1a)
        .equ gpiox_bsrr_br10_mask,              (0x01 << gpiox_bsrr_br10_position)
        .equ gpiox_bsrr_br10,                   (gpiox_bsrr_br10_mask)

        .equ gpiox_bsrr_br11_position,          (0x1b)
        .equ gpiox_bsrr_br11_mask,              (0x01 << gpiox_bsrr_br11_position)
        .equ gpiox_bsrr_br11,                   (gpiox_bsrr_br11_mask)

        .equ gpiox_bsrr_br12_position,          (0x1c)
        .equ gpiox_bsrr_br12_mask,              (0x01 << gpiox_bsrr_br12_position)
        .equ gpiox_bsrr_br12,                   (gpiox_bsrr_br12_mask)

        .equ gpiox_bsrr_br13_position,          (0x1d)
        .equ gpiox_bsrr_br13_mask,              (0x01 << gpiox_bsrr_br13_position)
        .equ gpiox_bsrr_br13,                   (gpiox_bsrr_br13_mask)

        .equ gpiox_bsrr_br14_position,          (0x1e)
        .equ gpiox_bsrr_br14_mask,              (0x01 << gpiox_bsrr_br14_position)
        .equ gpiox_bsrr_br14,                   (gpiox_bsrr_br14_mask)

        .equ gpiox_bsrr_br15_position,          (0x1f)
        .equ gpiox_bsrr_br15_mask,              (0x01 << gpiox_bsrr_br15_position)
        .equ gpiox_bsrr_br15,                   (gpiox_bsrr_br15_mask)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx LCKR register fields -----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_lckr_lckk0_position,         (0x00)
        .equ gpiox_lckr_lckk0_mask,             (0x01 << gpiox_lckr_lckk0_position)
        .equ gpiox_lckr_lckk0,                  (gpiox_lckr_lckk0_mask)

        .equ gpiox_lckr_lckk1_position,         (0x01)
        .equ gpiox_lckr_lckk1_mask,             (0x01 << gpiox_lckr_lckk1_position)
        .equ gpiox_lckr_lckk1,                  (gpiox_lckr_lckk1_mask)

        .equ gpiox_lckr_lckk2_position,         (0x02)
        .equ gpiox_lckr_lckk2_mask,             (0x01 << gpiox_lckr_lckk2_position)
        .equ gpiox_lckr_lckk2,                  (gpiox_lckr_lckk2_mask)

        .equ gpiox_lckr_lckk3_position,         (0x03)
        .equ gpiox_lckr_lckk3_mask,             (0x01 << gpiox_lckr_lckk3_position)
        .equ gpiox_lckr_lckk3,                  (gpiox_lckr_lckk3_mask)

        .equ gpiox_lckr_lckk4_position,         (0x04)
        .equ gpiox_lckr_lckk4_mask,             (0x01 << gpiox_lckr_lckk4_position)
        .equ gpiox_lckr_lckk4,                  (gpiox_lckr_lckk4_mask)

        .equ gpiox_lckr_lckk5_position,         (0x05)
        .equ gpiox_lckr_lckk5_mask,             (0x01 << gpiox_lckr_lckk5_position)
        .equ gpiox_lckr_lckk5,                  (gpiox_lckr_lckk5_mask)

        .equ gpiox_lckr_lckk6_position,         (0x06)
        .equ gpiox_lckr_lckk6_mask,             (0x01 << gpiox_lckr_lckk6_position)
        .equ gpiox_lckr_lckk6,                  (gpiox_lckr_lckk6_mask)

        .equ gpiox_lckr_lckk7_position,         (0x07)
        .equ gpiox_lckr_lckk7_mask,             (0x01 << gpiox_lckr_lckk7_position)
        .equ gpiox_lckr_lckk7,                  (gpiox_lckr_lckk7_mask)

        .equ gpiox_lckr_lckk8_position,         (0x08)
        .equ gpiox_lckr_lckk8_mask,             (0x01 << gpiox_lckr_lckk8_position)
        .equ gpiox_lckr_lckk8,                  (gpiox_lckr_lckk8_mask)

        .equ gpiox_lckr_lckk9_position,         (0x09)
        .equ gpiox_lckr_lckk9_mask,             (0x01 << gpiox_lckr_lckk9_position)
        .equ gpiox_lckr_lckk9,                  (gpiox_lckr_lckk9_mask)

        .equ gpiox_lckr_lckk10_position,        (0x0a)
        .equ gpiox_lckr_lckk10_mask,            (0x01 << gpiox_lckr_lckk10_position)
        .equ gpiox_lckr_lckk10,                 (gpiox_lckr_lckk10_mask)

        .equ gpiox_lckr_lckk11_position,        (0x0b)
        .equ gpiox_lckr_lckk11_mask,            (0x01 << gpiox_lckr_lckk11_position)
        .equ gpiox_lckr_lckk11,                 (gpiox_lckr_lckk11_mask)

        .equ gpiox_lckr_lckk12_position,        (0x0c)
        .equ gpiox_lckr_lckk12_mask,            (0x01 << gpiox_lckr_lckk12_position)
        .equ gpiox_lckr_lckk12,                 (gpiox_lckr_lckk12_mask)

        .equ gpiox_lckr_lckk13_position,        (0x0d)
        .equ gpiox_lckr_lckk13_mask,            (0x01 << gpiox_lckr_lckk13_position)
        .equ gpiox_lckr_lckk13,                 (gpiox_lckr_lckk13_mask)

        .equ gpiox_lckr_lckk14_position,        (0x0e)
        .equ gpiox_lckr_lckk14_mask,            (0x01 << gpiox_lckr_lckk14_position)
        .equ gpiox_lckr_lckk14,                 (gpiox_lckr_lckk14_mask)

        .equ gpiox_lckr_lckk15_position,        (0x0f)
        .equ gpiox_lckr_lckk15_mask,            (0x01 << gpiox_lckr_lckk15_position)
        .equ gpiox_lckr_lckk15,                 (gpiox_lckr_lckk15_mask)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx AFRL register fields -----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_afrl_afrl0_position,         (0x00)
        .equ gpiox_afrl_afrl0_mask,             (0x0f << gpiox_afrl_afrl0_position)
        .equ gpiox_afrl_afrl0,                  (gpiox_afrl_afrl0_mask)
        .equ gpiox_afrl_afrl0_bit0,             (0x01 << gpiox_afrl_afrl0_position)
        .equ gpiox_afrl_afrl0_bit1,             (0x02 << gpiox_afrl_afrl0_position)
        .equ gpiox_afrl_afrl0_bit2,             (0x04 << gpiox_afrl_afrl0_position)
        .equ gpiox_afrl_afrl0_bit3,             (0x08 << gpiox_afrl_afrl0_position)

        .equ gpiox_afrl_afrl1_position,         (0x04)
        .equ gpiox_afrl_afrl1_mask,             (0x0f << gpiox_afrl_afrl1_position)
        .equ gpiox_afrl_afrl1,                  (gpiox_afrl_afrl1_mask)
        .equ gpiox_afrl_afrl1_bit0,             (0x01 << gpiox_afrl_afrl1_position)
        .equ gpiox_afrl_afrl1_bit1,             (0x02 << gpiox_afrl_afrl1_position)
        .equ gpiox_afrl_afrl1_bit2,             (0x04 << gpiox_afrl_afrl1_position)
        .equ gpiox_afrl_afrl1_bit3,             (0x08 << gpiox_afrl_afrl1_position)

        .equ gpiox_afrl_afrl2_position,         (0x08)
        .equ gpiox_afrl_afrl2_mask,             (0x0f << gpiox_afrl_afrl2_position)
        .equ gpiox_afrl_afrl2,                  (gpiox_afrl_afrl2_mask)
        .equ gpiox_afrl_afrl2_bit0,             (0x01 << gpiox_afrl_afrl2_position)
        .equ gpiox_afrl_afrl2_bit1,             (0x02 << gpiox_afrl_afrl2_position)
        .equ gpiox_afrl_afrl2_bit2,             (0x04 << gpiox_afrl_afrl2_position)
        .equ gpiox_afrl_afrl2_bit3,             (0x08 << gpiox_afrl_afrl2_position)

        .equ gpiox_afrl_afrl3_position,         (0x0c)
        .equ gpiox_afrl_afrl3_mask,             (0x0f << gpiox_afrl_afrl3_position)
        .equ gpiox_afrl_afrl3,                  (gpiox_afrl_afrl3_mask)
        .equ gpiox_afrl_afrl3_bit0,             (0x01 << gpiox_afrl_afrl3_position)
        .equ gpiox_afrl_afrl3_bit1,             (0x02 << gpiox_afrl_afrl3_position)
        .equ gpiox_afrl_afrl3_bit2,             (0x04 << gpiox_afrl_afrl3_position)
        .equ gpiox_afrl_afrl3_bit3,             (0x08 << gpiox_afrl_afrl3_position)

        .equ gpiox_afrl_afrl4_position,         (0x10)
        .equ gpiox_afrl_afrl4_mask,             (0x0f << gpiox_afrl_afrl4_position)
        .equ gpiox_afrl_afrl4,                  (gpiox_afrl_afrl4_mask)
        .equ gpiox_afrl_afrl4_bit0,             (0x01 << gpiox_afrl_afrl4_position)
        .equ gpiox_afrl_afrl4_bit1,             (0x02 << gpiox_afrl_afrl4_position)
        .equ gpiox_afrl_afrl4_bit2,             (0x04 << gpiox_afrl_afrl4_position)
        .equ gpiox_afrl_afrl4_bit3,             (0x08 << gpiox_afrl_afrl4_position)

        .equ gpiox_afrl_afrl5_position,         (0x14)
        .equ gpiox_afrl_afrl5_mask,             (0x0f << gpiox_afrl_afrl5_position)
        .equ gpiox_afrl_afrl5,                  (gpiox_afrl_afrl5_mask)
        .equ gpiox_afrl_afrl5_bit0,             (0x01 << gpiox_afrl_afrl5_position)
        .equ gpiox_afrl_afrl5_bit1,             (0x02 << gpiox_afrl_afrl5_position)
        .equ gpiox_afrl_afrl5_bit2,             (0x04 << gpiox_afrl_afrl5_position)
        .equ gpiox_afrl_afrl5_bit3,             (0x08 << gpiox_afrl_afrl5_position)

        .equ gpiox_afrl_afrl6_position,         (0x18)
        .equ gpiox_afrl_afrl6_mask,             (0x0f << gpiox_afrl_afrl6_position)
        .equ gpiox_afrl_afrl6,                  (gpiox_afrl_afrl6_mask)
        .equ gpiox_afrl_afrl6_bit0,             (0x01 << gpiox_afrl_afrl6_position)
        .equ gpiox_afrl_afrl6_bit1,             (0x02 << gpiox_afrl_afrl6_position)
        .equ gpiox_afrl_afrl6_bit2,             (0x04 << gpiox_afrl_afrl6_position)
        .equ gpiox_afrl_afrl6_bit3,             (0x08 << gpiox_afrl_afrl6_position)

        .equ gpiox_afrl_afrl7_position,         (0x1c)
        .equ gpiox_afrl_afrl7_mask,             (0x0f << gpiox_afrl_afrl7_position)
        .equ gpiox_afrl_afrl7,                  (gpiox_afrl_afrl7_mask)
        .equ gpiox_afrl_afrl7_bit0,             (0x01 << gpiox_afrl_afrl7_position)
        .equ gpiox_afrl_afrl7_bit1,             (0x02 << gpiox_afrl_afrl7_position)
        .equ gpiox_afrl_afrl7_bit2,             (0x04 << gpiox_afrl_afrl7_position)
        .equ gpiox_afrl_afrl7_bit3,             (0x08 << gpiox_afrl_afrl7_position)


@-----------------------------------------------------------------------------------------------@
@-------------------------------- GPIOx AFRH register fields -----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ gpiox_afrh_afrh8_position,         (0x00)
        .equ gpiox_afrh_afrh8_mask,             (0x0f << gpiox_afrh_afrh8_position)
        .equ gpiox_afrh_afrh8,                  (gpiox_afrh_afrh8_mask)
        .equ gpiox_afrh_afrh8_bit0,             (0x01 << gpiox_afrh_afrh8_position)
        .equ gpiox_afrh_afrh8_bit1,             (0x02 << gpiox_afrh_afrh8_position)
        .equ gpiox_afrh_afrh8_bit2,             (0x04 << gpiox_afrh_afrh8_position)
        .equ gpiox_afrh_afrh8_bit3,             (0x08 << gpiox_afrh_afrh8_position)

        .equ gpiox_afrh_afrh9_position,         (0x04)
        .equ gpiox_afrh_afrh9_mask,             (0x0f << gpiox_afrh_afrh9_position)
        .equ gpiox_afrh_afrh9,                  (gpiox_afrh_afrh9_mask)
        .equ gpiox_afrh_afrh9_bit0,             (0x01 << gpiox_afrh_afrh9_position)
        .equ gpiox_afrh_afrh9_bit1,             (0x02 << gpiox_afrh_afrh9_position)
        .equ gpiox_afrh_afrh9_bit2,             (0x04 << gpiox_afrh_afrh9_position)
        .equ gpiox_afrh_afrh9_bit3,             (0x08 << gpiox_afrh_afrh9_position)

        .equ gpiox_afrh_afrh10_position,        (0x08)
        .equ gpiox_afrh_afrh10_mask,            (0x0f << gpiox_afrh_afrh10_position)
        .equ gpiox_afrh_afrh10,                 (gpiox_afrh_afrh10_mask)
        .equ gpiox_afrh_afrh10_bit0,            (0x01 << gpiox_afrh_afrh10_position)
        .equ gpiox_afrh_afrh10_bit1,            (0x02 << gpiox_afrh_afrh10_position)
        .equ gpiox_afrh_afrh10_bit2,            (0x04 << gpiox_afrh_afrh10_position)
        .equ gpiox_afrh_afrh10_bit3,            (0x08 << gpiox_afrh_afrh10_position)

        .equ gpiox_afrh_afrh11_position,        (0x0c)
        .equ gpiox_afrh_afrh11_mask,            (0x0f << gpiox_afrh_afrh11_position)
        .equ gpiox_afrh_afrh11,                 (gpiox_afrh_afrh11_mask)
        .equ gpiox_afrh_afrh11_bit0,            (0x01 << gpiox_afrh_afrh11_position)
        .equ gpiox_afrh_afrh11_bit1,            (0x02 << gpiox_afrh_afrh11_position)
        .equ gpiox_afrh_afrh11_bit2,            (0x04 << gpiox_afrh_afrh11_position)
        .equ gpiox_afrh_afrh11_bit3,            (0x08 << gpiox_afrh_afrh11_position)

        .equ gpiox_afrh_afrh12_position,        (0x10)
        .equ gpiox_afrh_afrh12_mask,            (0x0f << gpiox_afrh_afrh12_position)
        .equ gpiox_afrh_afrh12,                 (gpiox_afrh_afrh12_mask)
        .equ gpiox_afrh_afrh12_bit0,            (0x01 << gpiox_afrh_afrh12_position)
        .equ gpiox_afrh_afrh12_bit1,            (0x02 << gpiox_afrh_afrh12_position)
        .equ gpiox_afrh_afrh12_bit2,            (0x04 << gpiox_afrh_afrh12_position)
        .equ gpiox_afrh_afrh12_bit3,            (0x08 << gpiox_afrh_afrh12_position)

        .equ gpiox_afrh_afrh13_position,        (0x14)
        .equ gpiox_afrh_afrh13_mask,            (0x0f << gpiox_afrh_afrh13_position)
        .equ gpiox_afrh_afrh13,                 (gpiox_afrh_afrh13_mask)
        .equ gpiox_afrh_afrh13_bit0,            (0x01 << gpiox_afrh_afrh13_position)
        .equ gpiox_afrh_afrh13_bit1,            (0x02 << gpiox_afrh_afrh13_position)
        .equ gpiox_afrh_afrh13_bit2,            (0x04 << gpiox_afrh_afrh13_position)
        .equ gpiox_afrh_afrh13_bit3,            (0x08 << gpiox_afrh_afrh13_position)

        .equ gpiox_afrh_afrh14_position,        (0x18)
        .equ gpiox_afrh_afrh14_mask,            (0x0f << gpiox_afrh_afrh14_position)
        .equ gpiox_afrh_afrh14,                 (gpiox_afrh_afrh14_mask)
        .equ gpiox_afrh_afrh14_bit0,            (0x01 << gpiox_afrh_afrh14_position)
        .equ gpiox_afrh_afrh14_bit1,            (0x02 << gpiox_afrh_afrh14_position)
        .equ gpiox_afrh_afrh14_bit2,            (0x04 << gpiox_afrh_afrh14_position)
        .equ gpiox_afrh_afrh14_bit3,            (0x08 << gpiox_afrh_afrh14_position)

        .equ gpiox_afrh_afrh15_position,        (0x1c)
        .equ gpiox_afrh_afrh15_mask,            (0x0f << gpiox_afrh_afrh15_position)
        .equ gpiox_afrh_afrh15,                 (gpiox_afrh_afrh15_mask)
        .equ gpiox_afrh_afrh15_bit0,            (0x01 << gpiox_afrh_afrh15_position)
        .equ gpiox_afrh_afrh15_bit1,            (0x02 << gpiox_afrh_afrh15_position)
        .equ gpiox_afrh_afrh15_bit2,            (0x04 << gpiox_afrh_afrh15_position)
        .equ gpiox_afrh_afrh15_bit3,            (0x08 << gpiox_afrh_afrh15_position)


@-----------------------------------------------------------------------------------------------@
