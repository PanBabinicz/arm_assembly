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
.data
VARIABLES:
BLINK_PATTERN_STEP:
  .space 1
.align 2
TIMER_STEP:
  .space 1
.align 2
FLAG_ON_OFF:
  .space 1

.align 2
.text
.type BLINK_PATTERN_START, %object
BLINK_PATTERN_START:
  .byte 2, 5, 5, 5, 2, 5
  .byte 5, 2, 2, 2, 5, 2
BLINK_PATTERN_END:

.align 2
.type _RESET_HANDLER, %function
.global _RESET_HANDLER
_RESET_HANDLER:
  bl _set_rcc_clock
  bl _set_gpio_output
  bl _blink_pattern_restart
  @ Turn on the led.
  ldr r1, =STM32_GPIOx_BSRR_BASE
  mov r0, #STM32_GPIOx_BSRR_BS5
  str r0, [r1]
  @ Configure the systick.
  ldr r0, =STK_COUNT_DOWN_VALUE
  bl _configure_systick
_sleep_loop:
  wfi
  b _sleep_loop
  .ltorg
.type _set_rcc_clock, %function
_set_rcc_clock:
  ldr r1, =STM32_RCC_AHB1ENR_BASE
  ldr r0, [r1]
  orr r0, #STM32_RCC_AHB1ENR_GPIOAEN
  str r0, [r1]
  bx lr
  .ltorg
.type _set_gpio_output, %function
_set_gpio_output:
  ldr r1, =STM32_GPIOx_MODER_BASE
  ldr r0, [r1]
  orr r0, #STM32_GPIOx_MODER_OUTPUT_5
  str r0, [r1]
  bx lr
  .ltorg
.type _configure_systick, %function
_configure_systick:
  ldr r1, =STM32_STK_BASE
  str r0, [r1, #STM32_STK_LOAD_OFFSET]
  mov r0, #0x00
  str r0, [r1, #STM32_STK_VAL_OFFSET]
  mov r0, #0x03
  str r0, [r1, #STM32_STK_CTRL_OFFSET]
  bx lr
  .ltorg
.type _SYSTICK_HANDLER, %function
.global _SYSTICK_HANDLER
_SYSTICK_HANDLER:
  ldr r1, =STM32_STK_BASE
  ldr r0, [r1, #STM32_STK_CTRL_OFFSET]
  tst r0, 0x10000
  beq _return
  ldr r1, =VARIABLES
  @ Check the step in blink pattern array.
  ldrb r0, [r1, #(BLINK_PATTERN_STEP-VARIABLES)]
  cmp r0, #(BLINK_PATTERN_END-BLINK_PATTERN_START)
  bhs _blink_pattern_restart
  ldrb r2, [r1, #(TIMER_STEP-VARIABLES)]
  subs r2, #1
  itt ne
  strbne r2, [r1, #(TIMER_STEP-VARIABLES)]
  bne _return
  ldr r5, =STM32_GPIOx_BSRR_BASE
  ldr r4, [r1, #(FLAG_ON_OFF-VARIABLES)]
  tst r4, 0x01
  beq _store_next_one
  mov r4, #0x00
  strb r4, [r1, #(FLAG_ON_OFF-VARIABLES)]
  mov r6, #STM32_GPIOx_BSRR_BR5
  str r6, [r5]
  ldrb r3, =BLINK_PATTERN_START
  ldrb r2, [r3, r0]
  strb r2, [r1, #(TIMER_STEP-VARIABLES)]
  bx lr
  .ltorg
_store_next_one:
  mov r4, #0x01
  strb r4, [r1, #(FLAG_ON_OFF-VARIABLES)]
  mov r6, #STM32_GPIOx_BSRR_BS5
  str r6, [r5]
  add r0, #1
  ldr r3, =BLINK_PATTERN_START
  ldrb r2, [r3, r0]
  strb r2, [r1, #(TIMER_STEP-VARIABLES)]
  strb r0, [r1, #(BLINK_PATTERN_STEP-VARIABLES)]
  bx lr
_blink_pattern_restart:
  @ Initialize the RAM variables.
  ldr r1, =VARIABLES
  mov r0, #0x00
  str r0, [r1, #(BLINK_PATTERN_STEP-VARIABLES)]
  mov r0, #0x01
  str r0, [r1, #(FLAG_ON_OFF-VARIABLES)]
  ldrb r0, BLINK_PATTERN_START
  strb r0, [r1, #(TIMER_STEP-VARIABLES)]
_return:
  bx lr
  .ltorg
