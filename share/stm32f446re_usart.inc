        .syntax unified
        .cpu cortex-m4
        .thumb


@-----------------------------------------------------------------------------------------------@
@--------------------------------- USART registers offsets -------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ usart1_base,                       (0x40011000)    @ USART1 register boundary
                                                                @ address

        .equ usart2_base,                       (0x40004400)    @ USART2 register boundary
                                                                @ address

        .equ usart3_base,                       (0x40004800)    @ USART3 register boundary
                                                                @ address

        .equ uart4_base,                        (0x40004c00)    @ UART4 register boundary
                                                                @ address

        .equ uart5_base,                        (0x40005000)    @ UART5 register boundary
                                                                @ address

        .equ usart6_base,                       (0x40011400)    @ USART6 register boundary
                                                                @ address

        .equ usart_sr_offset,                   (0x00)          @ USART status register
                                                                @ offset

        .equ usart_dr_offset,                   (0x04)          @ USART data register
                                                                @ offset

        .equ usart_brr_offset,                  (0x08)          @ USART baud rate register
                                                                @ offset

        .equ usart_cr1_offset,                  (0x0c)          @ USART control register 1
                                                                @ offset

        .equ usart_cr2_offset,                  (0x10)          @ USART control register 2
                                                                @ offset

        .equ usart_cr3_offset,                  (0x14)          @ USART control register 3
                                                                @ offset

        .equ usart_gtpr_offset,                 (0x18)          @ USART guard time and
                                                                @ prescaler register offset


@-----------------------------------------------------------------------------------------------@
@--------------------------------- USART SR register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ usart_sr_pe_position,              (0x00)
        .equ usart_sr_pe_mask,                  (0x01 << usart_sr_pe_position)
        .equ usart_sr_pe,                       (usart_sr_pe_mask)

        .equ usart_sr_fe_position,              (0x01)
        .equ usart_sr_fe_mask,                  (0x01 << usart_sr_fe_position)
        .equ usart_sr_fe,                       (usart_sr_fe_mask)

        .equ usart_sr_nf_position,              (0x02)
        .equ usart_sr_nf_mask,                  (0x01 << usart_sr_nf_position)
        .equ usart_sr_nf,                       (usart_sr_nf_mask)

        .equ usart_sr_ore_position,             (0x03)
        .equ usart_sr_ore_mask,                 (0x01 << usart_sr_ore_position)
        .equ usart_sr_ore,                      (usart_sr_ore_mask)

        .equ usart_sr_idle_position,            (0x04)
        .equ usart_sr_idle_mask,                (0x01 << usart_sr_idle_position)
        .equ usart_sr_idle,                     (usart_sr_idle_mask)

        .equ usart_sr_rxne_position,            (0x05)
        .equ usart_sr_rxne_mask,                (0x01 << usart_sr_rxne_position)
        .equ usart_sr_rxne,                     (usart_sr_rxne_mask)

        .equ usart_sr_tc_position,              (0x06)
        .equ usart_sr_tc_mask,                  (0x01 << usart_sr_tc_position)
        .equ usart_sr_tc,                       (usart_sr_tc_mask)

        .equ usart_sr_txe_position,             (0x07)
        .equ usart_sr_txe_mask,                 (0x01 << usart_sr_txe_position)
        .equ usart_sr_txe,                      (usart_sr_txe_mask)

        .equ usart_sr_lbd_position,             (0x08)
        .equ usart_sr_lbd_mask,                 (0x01 << usart_sr_lbd_position)
        .equ usart_sr_lbd,                      (usart_sr_lbd_mask)

        .equ usart_sr_cts_position,             (0x09)
        .equ usart_sr_cts_mask,                 (0x01 << usart_sr_cts_position)
        .equ usart_sr_cts,                      (usart_sr_cts_mask)


@-----------------------------------------------------------------------------------------------@
@--------------------------------- USART DR register fields ------------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ usart_dr_dr_position,              (0x00)
        .equ usart_dr_dr_mask,                  (0x1ff << usart_dr_dr_position)
        .equ usart_dr_dr,                       (usart_dr_dr_mask)
        .equ usart_dr_dr_bit0,                  (0x0001 << usart_dr_dr_position)
        .equ usart_dr_dr_bit1,                  (0x0002 << usart_dr_dr_position)
        .equ usart_dr_dr_bit2,                  (0x0004 << usart_dr_dr_position)
        .equ usart_dr_dr_bit3,                  (0x0008 << usart_dr_dr_position)
        .equ usart_dr_dr_bit4,                  (0x0010 << usart_dr_dr_position)
        .equ usart_dr_dr_bit5,                  (0x0020 << usart_dr_dr_position)
        .equ usart_dr_dr_bit6,                  (0x0040 << usart_dr_dr_position)
        .equ usart_dr_dr_bit7,                  (0x0080 << usart_dr_dr_position)
        .equ usart_dr_dr_bit8,                  (0x0100 << usart_dr_dr_position)


@-----------------------------------------------------------------------------------------------@
@--------------------------------- USART BRR register fields -----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ usart_brr_divfraction_position,    (0x00)
        .equ usart_brr_divfraction_mask,        (0x0f << usart_brr_divfraction_position)
        .equ usart_brr_divfraction,             (usart_brr_divfraction_mask)
        .equ usart_brr_divfraction_bit0,        (0x01 << usart_brr_divfraction_position)
        .equ usart_brr_divfraction_bit1,        (0x02 << usart_brr_divfraction_position)
        .equ usart_brr_divfraction_bit2,        (0x04 << usart_brr_divfraction_position)
        .equ usart_brr_divfraction_bit3,        (0x08 << usart_brr_divfraction_position)

        .equ usart_brr_divmantissa_position,    (0x04)
        .equ usart_brr_divmantissa_mask,        (0x0fff << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa,             (usart_brr_divmantissa_mask)
        .equ usart_brr_divmantissa_bit0,        (0x0001 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit1,        (0x0002 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit2,        (0x0004 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit3,        (0x0008 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit4,        (0x0010 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit5,        (0x0020 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit6,        (0x0040 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit7,        (0x0080 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit8,        (0x0100 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit9,        (0x0200 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit10,       (0x0400 << usart_brr_divmantissa_position)
        .equ usart_brr_divmantissa_bit11,       (0x0800 << usart_brr_divmantissa_position)


@-----------------------------------------------------------------------------------------------@
