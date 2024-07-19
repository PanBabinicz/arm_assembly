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

.text
.type _RESET_HANDLER, %function
.global _RESET_HANDLER
_RESET_HANDLER:
  bl turn_on_gpio_clock
  bl set_gpio_mode_output
  ldr r5, =10
  bl blink
  b .
turn_on_gpio_clock:
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
  push { lr }
  ldr r0, =STM32_GPIOx_BSRR_BASE
  ldr r1, =STM32_GPIOx_BSRR_BS5
  ldr r2, =STM32_GPIOx_BSRR_BR5
  ldr r3, =BLINK_LOOP_SIZE
blink_count:
  str r1, [r0]
  mov r4, r3
  bl blink_delay
  str r2, [r0]
  mov r4, r3
  bl blink_delay
  subs r5, #1
  bne blink_count
  pop { pc }
blink_delay:
  subs r4, #1
  bne blink_delay
  bx lr
