        .syntax unified
        .cpu cortex-m4
        .thumb


@-----------------------------------------------------------------------------------------------@
@---------------------------------- SYSTICK registers offsets ----------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ stk_base,              (0xe000e010)    @ SysTick register boundary address

        .equ stk_ctrl_offset,       (0x00)          @ SysTick control and status register
        .equ stk_load_offset,       (0x04)          @ SysTick reload value register
        .equ stk_val_offset,        (0x08)          @ SysTick current value register
        .equ stk_calib_offset,      (0x0c)          @ SysTick calibration value register


@-----------------------------------------------------------------------------------------------@
@--------------------------------- SYSTICK CTRL register fields --------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ stk_ctrl_enable_position,      (0x00)
        .equ stk_ctrl_enable_mask,          (0x01 << stk_ctrl_enable_position)
        .equ stk_ctrl_enable,               (stk_ctrl_enable_mask)

        .equ stk_ctrl_tickint_position,     (0x01)
        .equ stk_ctrl_tickint_mask,         (0x01 << stk_ctrl_tickint_position)
        .equ stk_ctrl_tickint,              (stk_ctrl_tickint_mask)

        .equ stk_ctrl_clksource_position,   (0x02)
        .equ stk_ctrl_clksource_mask,       (0x01 << stk_ctrl_clksource_position)
        .equ stk_ctrl_clksource,            (stk_ctrl_clksource_mask)

        .equ stk_ctrl_countflag_position,   (0x10)
        .equ stk_ctrl_countflag_mask,       (0x01 << stk_ctrl_countflag_position)
        .equ stk_ctrl_countflag,            (stk_ctrl_countflag_mask)


@-----------------------------------------------------------------------------------------------@
@--------------------------------- SYSTICK LOAD register fields --------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ stk_load_reload_position,      (0x00)
        .equ stk_load_reload_mask,          (0xffffff << stk_load_reload_position)


@-----------------------------------------------------------------------------------------------@
@--------------------------------- SYSTICK VAL register fields ---------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ stk_val_current_position,      (0x00)
        .equ stk_val_current_mask,          (0xffffff << stk_val_current_position)


@-----------------------------------------------------------------------------------------------@
@--------------------------------- SYSTICK CALIB register fields -------------------------------@
@-----------------------------------------------------------------------------------------------@

        .equ stk_calib_tenms_position,      (0x00)
        .equ stk_calib_tenms_mask,          (0xffffff << stk_calib_tenms_position)

        .equ stk_calib_skew_position,       (0x1e)
        .equ stk_calib_skew_mask,           (0x01 << stk_calib_skew_position)
        .equ stk_calib_skew,                (stk_calib_skew_mask)

        .equ stk_calib_noref_position,      (0x1f)
        .equ stk_calib_noref_mask,          (0x01 << stk_calib_noref_position)
        .equ stk_calib_noref,               (stk_calib_noref_mask)


@-----------------------------------------------------------------------------------------------@
