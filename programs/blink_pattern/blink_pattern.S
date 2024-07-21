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

BLINK_LOOP_SIZE = 1000000

@ Blink pattern table
.align 2
.type BLINK_PATTERN_START, %object
BLINK_PATTERN_START:
  .word 1000000, 1500000, 2000000, 2500000, 3000000, 3500000 ,4000000
  .word 4000000, 3500000, 3000000, 2500000, 2000000, 1500000, 1000000
BLINK_PATTERN_END:

.text
.type _RESET_HANDLER, %function
.globl _RESET_HANDLER
_RESET_HANDLER:
  bl set_rcc_clock
  bl set_gpio_mode_output
  bl blink
  b .
set_rcc_clock:
  ldr r0, =STM32_RCC_AHB1ENR_BASE
  ldr r1, [r0]
  orr r1, #STM32_RCC_AHB1ENR_GPIOAEN
  str r1, [r0]
  bx lr
set_gpio_mode_output:
  ldr r0, =STM32_GPIOx_MODER_BASE
  ldr r1, [r0]
  orr r1, #STM32_GPIOx_MODER_OUTPUT_5
  str r1, [r0]
  bx lr
blink:
  push { r4-r8, lr }
  ldr r4, =STM32_GPIOx_BSRR_BASE
  ldr r5, =STM32_GPIOx_BSRR_BS5
  ldr r6, =STM32_GPIOx_BSRR_BR5
  ldr r7, =BLINK_PATTERN_START
  ldr r8, =BLINK_PATTERN_END
blink_count:
  str r5, [r4]
  ldr r0, [r7], #4
  bl blink_delay
  str r6, [r4]
  ldr r0, [r7]
  bl blink_delay
  cmp r7, r8
  blo blink_count
  pop { r4-r8, lr }
blink_delay:
  subs r0, #1
  bne blink_delay
  bx lr
