.syntax unified
.cpu cortex-m4
.thumb

.section ._VECTOR_TABLE, "a"
.word _STACK_END
.word _RESET_HANDLER
.space 0xe4

.data
.var1:
  .space 4
.var2:
  .space 1

.text
.type _RESET_HANDLER, %function
_RESET_HANDLER:
  ldr r0, =0x123456
  mov r1, r0
  and r0, #0xf
  mov r2, r0
  b .
