.syntax unified
.cpu cortex-m4
.thumb

@ Constant addresses and values
STM32_RCC_AHB1ENR_BASE = 0x40023830
STM32_RCC_AHB1ENR_GPIOAEN = 0x1

STM32_GPIOx_MODER_BASE = 0x40020000
STM32_GPIOx_MODER_INPUT_5 = 0x0 << 10
STM32_GPIOx_MODER_OUTPUT_5 = 0x1 << 10
STM32_GPIOx_MODER_AF_5 = 0x2 << 10
STM32_GPIOx_MODER_ANALOG_5 = 0x3 << 10

STM32_GPIOx_BSRR_BASE = 0x40020018
STM32_GPIOx_BSRR_BS5 = 0x1 << 5
STM32_GPIOx_BSRR_BR5 = 0x1 << 21

STM32_STK_BASE = 0xe000e010
STM32_STK_CTRL_OFFSET = 0x00
STM32_STK_LOAD_OFFSET = 0x04
STM32_STK_VAL_OFFSET = 0x08
STM32_STK_CALIB_OFFSET = 0x0c

STK_COUNT_DOWN_VALUE = 1500000

.align 2
.type BLINK_PATTERN_START, %object
BLINK_PATTERN_START:
  .byte 2, 5, 5, 5, 2, 5
  .byte 5, 2, 2, 2, 5, 2
BLINK_PATTERN_END:
.align 2

.text
.type _RESET_HANDLER, %function
.global _RESET_HANDLER
_RESET_HANDLER:
  bl _set_rcc_clock
  bl _set_gpio_mode_output
  ldr r0, =STK_COUNT_DOWN_VALUE
  bl _set_stk
  bl _blink
.type _set_rcc_clock, %function
_set_rcc_clock:
  ldr r1, =STM32_RCC_AHB1ENR_BASE
  ldr r0, [r1]
  orr r0, r0, #STM32_RCC_AHB1ENR_GPIOAEN
  str r0, [r1]
  bx lr
.type _set_gpio_mode_output, %function
_set_gpio_mode_output:
  ldr r1, =STM32_GPIOx_MODER_BASE
  ldr r0, [r1]
  orr r0, r0, #STM32_GPIOx_MODER_OUTPUT_5
  str r0, [r1]
  bx lr
@ Parameter r0: Count down value for timer.
.type _set_stk, %function
_set_stk:
  ldr r1, =STM32_STK_BASE
  str r0, [r1, #STM32_STK_LOAD_OFFSET]
  mov r0, #0x00
  str r0, [r1, #STM32_STK_VAL_OFFSET]
  mov r0, #0x01
  str r0, [r1, #STM32_STK_CTRL_OFFSET]
  bx lr
.type _read_stk, %function
_read_stk:
  ldr r1, =STM32_STK_BASE
_read_stk_loop:
  ldr r2, [r1, #STM32_STK_CTRL_OFFSET]
  tst r2, 0x10000
  beq _read_stk_loop
  subs r0, #1
  bne _read_stk_loop
  bx lr
.type _blink, %function
_blink:
  push { r4-r8, lr }
  ldr r4, =STM32_GPIOx_BSRR_BASE
  ldr r5, =STM32_GPIOx_BSRR_BS5
  ldr r6, =STM32_GPIOx_BSRR_BR5
  adr r7, BLINK_PATTERN_START
  adr r8, BLINK_PATTERN_END
_blink_loop:
  str r5, [r4]
  ldrb r0, [r7]
  bl _read_stk
  str r6, [r4]
  ldrb r0, [r7], #1
  bl _read_stk
  cmp r7, r8
  blo _blink_loop
  pop { r4-r8, lr }
  











