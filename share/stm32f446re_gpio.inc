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

    .equ gpiox_moder_moder0_position,   (0x00)
    .equ gpiox_moder_moder0_mask,       (0x03 << gpiox_moder_moder0_position)
    .equ gpiox_moder_moder0,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder0_bit0,       (0x01 << gpiox_moder_moder0_position)
    .equ gpiox_moder_moder0_bit1,       (0x02 << gpiox_moder_moder0_position)

    .equ gpiox_moder_moder1_position,   (0x02)
    .equ gpiox_moder_moder1_mask,       (0x03 << gpiox_moder_moder1_position)
    .equ gpiox_moder_moder1,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder1_bit0,       (0x01 << gpiox_moder_moder1_position)
    .equ gpiox_moder_moder1_bit1,       (0x02 << gpiox_moder_moder1_position)

    .equ gpiox_moder_moder2_position,   (0x04)
    .equ gpiox_moder_moder2_mask,       (0x03 << gpiox_moder_moder2_position)
    .equ gpiox_moder_moder2,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder2_bit0,       (0x01 << gpiox_moder_moder2_position)
    .equ gpiox_moder_moder2_bit1,       (0x02 << gpiox_moder_moder2_position)

    .equ gpiox_moder_moder3_position,   (0x06)
    .equ gpiox_moder_moder3_mask,       (0x03 << gpiox_moder_moder3_position)
    .equ gpiox_moder_moder3,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder3_bit0,       (0x01 << gpiox_moder_moder3_position)
    .equ gpiox_moder_moder3_bit1,       (0x02 << gpiox_moder_moder3_position)

    .equ gpiox_moder_moder4_position,   (0x08)
    .equ gpiox_moder_moder4_mask,       (0x03 << gpiox_moder_moder4_position)
    .equ gpiox_moder_moder4,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder4_bit0,       (0x01 << gpiox_moder_moder4_position)
    .equ gpiox_moder_moder4_bit1,       (0x02 << gpiox_moder_moder4_position)

    .equ gpiox_moder_moder5_position,   (0x0a)
    .equ gpiox_moder_moder5_mask,       (0x03 << gpiox_moder_moder5_position)
    .equ gpiox_moder_moder5,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder5_bit0,       (0x01 << gpiox_moder_moder5_position)
    .equ gpiox_moder_moder5_bit1,       (0x02 << gpiox_moder_moder5_position)

    .equ gpiox_moder_moder6_position,   (0x0c)
    .equ gpiox_moder_moder6_mask,       (0x03 << gpiox_moder_moder6_position)
    .equ gpiox_moder_moder6,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder6_bit0,       (0x01 << gpiox_moder_moder6_position)
    .equ gpiox_moder_moder6_bit1,       (0x02 << gpiox_moder_moder6_position)

    .equ gpiox_moder_moder7_position,   (0x0e)
    .equ gpiox_moder_moder7_mask,       (0x03 << gpiox_moder_moder7_position)
    .equ gpiox_moder_moder7,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder7_bit0,       (0x01 << gpiox_moder_moder7_position)
    .equ gpiox_moder_moder7_bit1,       (0x02 << gpiox_moder_moder7_position)

    .equ gpiox_moder_moder8_position,   (0x10)
    .equ gpiox_moder_moder8_mask,       (0x03 << gpiox_moder_moder8_position)
    .equ gpiox_moder_moder8,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder8_bit0,       (0x01 << gpiox_moder_moder8_position)
    .equ gpiox_moder_moder8_bit1,       (0x02 << gpiox_moder_moder8_position)

    .equ gpiox_moder_moder9_position,   (0x12)
    .equ gpiox_moder_moder9_mask,       (0x03 << gpiox_moder_moder9_position)
    .equ gpiox_moder_moder9,            (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder9_bit0,       (0x01 << gpiox_moder_moder9_position)
    .equ gpiox_moder_moder9_bit1,       (0x02 << gpiox_moder_moder9_position)

    .equ gpiox_moder_moder10_position,  (0x14)
    .equ gpiox_moder_moder10_mask,      (0x03 << gpiox_moder_moder10_position)
    .equ gpiox_moder_moder10,           (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder10_bit0,      (0x01 << gpiox_moder_moder10_position)
    .equ gpiox_moder_moder10_bit1,      (0x02 << gpiox_moder_moder10_position)

    .equ gpiox_moder_moder11_position,  (0x16)
    .equ gpiox_moder_moder11_mask,      (0x03 << gpiox_moder_moder11_position)
    .equ gpiox_moder_moder11,           (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder11_bit0,      (0x01 << gpiox_moder_moder11_position)
    .equ gpiox_moder_moder11_bit1,      (0x02 << gpiox_moder_moder11_position)

    .equ gpiox_moder_moder12_position,  (0x18)
    .equ gpiox_moder_moder12_mask,      (0x03 << gpiox_moder_moder12_position)
    .equ gpiox_moder_moder12,           (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder12_bit0,      (0x01 << gpiox_moder_moder12_position)
    .equ gpiox_moder_moder12_bit1,      (0x02 << gpiox_moder_moder12_position)

    .equ gpiox_moder_moder13_position,  (0x1a)
    .equ gpiox_moder_moder13_mask,      (0x03 << gpiox_moder_moder13_position)
    .equ gpiox_moder_moder13,           (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder13_bit0,      (0x01 << gpiox_moder_moder13_position)
    .equ gpiox_moder_moder13_bit1,      (0x02 << gpiox_moder_moder13_position)

    .equ gpiox_moder_moder14_position,  (0x1c)
    .equ gpiox_moder_moder14_mask,      (0x03 << gpiox_moder_moder14_position)
    .equ gpiox_moder_moder14,           (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder14_bit0,      (0x01 << gpiox_moder_moder14_position)
    .equ gpiox_moder_moder14_bit1,      (0x02 << gpiox_moder_moder14_position)

    .equ gpiox_moder_moder15_position,  (0x1e)
    .equ gpiox_moder_moder15_mask,      (0x03 << gpiox_moder_moder15_position)
    .equ gpiox_moder_moder15,           (gpiox_moder_moder0_mask)
    .equ gpiox_moder_moder15_bit0,      (0x01 << gpiox_moder_moder15_position)
    .equ gpiox_moder_moder15_bit1,      (0x02 << gpiox_moder_moder15_position)


@-----------------------------------------------------------------------------------------------@
@--------------------------------- GPIOx OTYPE register fields ---------------------------------@
@-----------------------------------------------------------------------------------------------@

    .equ gpiox_otyper_ot0_position,     (0x00)
    .equ gpiox_otyper_ot0_mask,         (0x01 << gpiox_otyper_ot0_position)
    .equ gpiox_otyper_ot0,              (gpiox_otyper_ot0_mask)

    .equ gpiox_otyper_ot1_position,     (0x01)
    .equ gpiox_otyper_ot1_mask,         (0x01 << gpiox_otyper_ot1_position)
    .equ gpiox_otyper_ot1,              (gpiox_otyper_ot1_mask)

    .equ gpiox_otyper_ot2_position,     (0x02)
    .equ gpiox_otyper_ot2_mask,         (0x01 << gpiox_otyper_ot2_position)
    .equ gpiox_otyper_ot2,              (gpiox_otyper_ot2_mask)

    .equ gpiox_otyper_ot3_position,     (0x03)
    .equ gpiox_otyper_ot3_mask,         (0x01 << gpiox_otyper_ot3_position)
    .equ gpiox_otyper_ot3,              (gpiox_otyper_ot3_mask)

    .equ gpiox_otyper_ot4_position,     (0x04)
    .equ gpiox_otyper_ot4_mask,         (0x01 << gpiox_otyper_ot4_position)
    .equ gpiox_otyper_ot4,              (gpiox_otyper_ot4_mask)

    .equ gpiox_otyper_ot5_position,     (0x05)
    .equ gpiox_otyper_ot5_mask,         (0x01 << gpiox_otyper_ot5_position)
    .equ gpiox_otyper_ot5,              (gpiox_otyper_ot5_mask)

    .equ gpiox_otyper_ot6_position,     (0x06)
    .equ gpiox_otyper_ot6_mask,         (0x01 << gpiox_otyper_ot6_position)
    .equ gpiox_otyper_ot6,              (gpiox_otyper_ot6_mask)

    .equ gpiox_otyper_ot7_position,     (0x07)
    .equ gpiox_otyper_ot7_mask,         (0x01 << gpiox_otyper_ot7_position)
    .equ gpiox_otyper_ot7,              (gpiox_otyper_ot7_mask)

    .equ gpiox_otyper_ot8_position,     (0x08)
    .equ gpiox_otyper_ot8_mask,         (0x01 << gpiox_otyper_ot8_position)
    .equ gpiox_otyper_ot8,              (gpiox_otyper_ot8_mask)

    .equ gpiox_otyper_ot9_position,     (0x09)
    .equ gpiox_otyper_ot9_mask,         (0x01 << gpiox_otyper_ot9_position)
    .equ gpiox_otyper_ot9,              (gpiox_otyper_ot9_mask)

    .equ gpiox_otyper_ot10_position,    (0x0a)
    .equ gpiox_otyper_ot10_mask,        (0x01 << gpiox_otyper_ot10_position)
    .equ gpiox_otyper_ot10,             (gpiox_otyper_ot10_mask)

    .equ gpiox_otyper_ot11_position,    (0x0b)
    .equ gpiox_otyper_ot11_mask,        (0x01 << gpiox_otyper_ot11_position)
    .equ gpiox_otyper_ot11,             (gpiox_otyper_ot11_mask)

    .equ gpiox_otyper_ot12_position,    (0x0c)
    .equ gpiox_otyper_ot12_mask,        (0x01 << gpiox_otyper_ot12_position)
    .equ gpiox_otyper_ot12,             (gpiox_otyper_ot12_mask)

    .equ gpiox_otyper_ot13_position,    (0x0d)
    .equ gpiox_otyper_ot13_mask,        (0x01 << gpiox_otyper_ot13_position)
    .equ gpiox_otyper_ot13,             (gpiox_otyper_ot13_mask)

    .equ gpiox_otyper_ot14_position,    (0x0e)
    .equ gpiox_otyper_ot14_mask,        (0x01 << gpiox_otyper_ot14_position)
    .equ gpiox_otyper_ot14,             (gpiox_otyper_ot14_mask)

    .equ gpiox_otyper_ot15_position,    (0x0f)
    .equ gpiox_otyper_ot15_mask,        (0x01 << gpiox_otyper_ot15_position)
    .equ gpiox_otyper_ot15,             (gpiox_otyper_ot15_mask)


@-----------------------------------------------------------------------------------------------@
