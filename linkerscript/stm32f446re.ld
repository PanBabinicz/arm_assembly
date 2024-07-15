MEMORY {
  FLASH : ORIGIN = 0x8000000,   LENGTH = 512K
  SRAM  : ORIGIN = 0x20000000,  LENGTH = 128K
}

SECTIONS {
  ._VECTOR_TABLE : {
    *(._VECTOR_TABLE)
  } >FLASH

  .text : {
    *(.text)
  } >FLASH

  .data (NOLOAD) : {
    . = . + 0x400;
    _STACK_END = .;
    *(.data)
  } >SRAM
}
