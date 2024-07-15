.syntax unified
.cpu cortex-m4
.thumb

.section ._VECTOR_TABLE, "a"
.word _STACK_END
.word _RESET_HANDLER
.space 0xe4
