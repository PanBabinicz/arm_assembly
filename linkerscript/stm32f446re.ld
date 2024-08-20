MEMORY {
  flash : ORIGIN = 0x8000000,   LENGTH = 512K
  sram  : ORIGIN = 0x20000000,  LENGTH = 128K
}

SECTIONS {
  ._vector_table : {
    *(._vector_table)
  } >flash

  .text : {
    *(.text)
  } >flash

  .data (NOLOAD) : {
    . = . + 0x400;
    _stack_end = .;
    *(.data)
  } >sram
}
