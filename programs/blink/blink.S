.syntax unified
.cpu cortex-m4
.thumb

.word 0x20000400
.word 0x080000ed
.space 0xe4

ldr r0, =0x40023830
ldr r1, =0x40020000
ldr r2, =0x40020018

blink_loop:
  @ RCC enable for GPIOA
  ldr r3, [r0]
  orr r3, #0x1
  str r3, [r0]
  @ Set GPIOA pin5 to output
  ldr r3, [r1]
  orr r3, #0x400
  str r3, [r1]
  @ Set GPIOA pin5 output high
  ldr r3, [r2]
  orr r3, #0x20
  str r3, [r2]
  ldr r3, =1000000
delay_on:
  subs r3, #1
  bne delay_on
  @ Set GPIOA pin5 output low
  ldr r3, [r2]
  orr r3, #0x200000
  str r3, [r2]
  ldr r3, =1000000
delay_off:
  subs r3, #1
  bne delay_off
  b blink_loop
