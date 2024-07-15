.syntax unified
.cpu cortex-m4
.thumb

.text
.type _RESET_HANDLER, %function
.global _RESET_HANDLER
_RESET_HANDLER:
  @ RCC enable for GPIOA
  ldr r0, =0x40023830
  ldr r1, [r0]
  orr r1, #0x1
  str r1, [r0]
  @ Set GPIOA pin5 to output
  ldr r0, =0x40020000
  ldr r1, [r0]
  orr r1, #0x400
  str r1, [r0]
  @ Store the constant values for setting leds on/off
  ldr r0, =0x40020018
  ldr r1, =0x20
  ldr r2, =0x200000
  ldr r3, =1000000
blink_loop:
  @ Set GPIOA pin5 output high
  str r1, [r0]
  mov r4, r3
delay_on:
  subs r4, #1
  bne delay_on
  @ Set GPIOA pin5 output low
  str r2, [r0]
  mov r4, r3
delay_off:
  subs r4, #1
  bne delay_off
  b blink_loop
