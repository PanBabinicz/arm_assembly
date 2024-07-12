.SYNTax unified
.cpu cortex-m4
.thumb

.word 0x20000400
.word 0x080000ed
.space 0xe4

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

@ Set GPIOA pin5 output high
ldr r0, =0x40020018
ldr r1, [r0]
orr r1, #0x20
str r1, [r0]

b .
