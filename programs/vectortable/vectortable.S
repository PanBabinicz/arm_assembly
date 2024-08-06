.syntax unified
.cpu cortex-m4
.thumb

.macro defisr name
  .type \name, %function
  .global \name
  .weak \name
  .thumb_set \name, _DEFAULT_HANDLER
  .word \name
.endm

.global _VECTOR_TABLE
.section ._VECTOR_TABLE, "a"
.type _VECTOR_TABLE, %object
_VECTOR_TABLE:
  .word _STACK_END
  defisr _RESET_HANDLER
  defisr _NMI_HANDLER
  defisr _HARDFAULT_HANDLER
  defisr _MEMMANAGE_HANDLER
  defisr _BUSFAULT_HANDLER
  defisr _USAGEFAULT_HANDLER
  .word 0
  .word 0
  .word 0
  .word 0
  defisr _SVCALL_HANDLER
  defisr _DEBUGMONITOR_HANDLER
  .word 0
  defisr _PENDSV_HANDLER
  defisr _SYSTICK_HANDLER
  defisr _WWDG_HANDLER
  defisr _PVD_HANDLER
  defisr _TAMPSTAMP_HANDLER
  defisr _RTCWKUP_HANDLER
  defisr _FLASH_HANDLER
  defisr _RCC_HANDLER
  defisr _EXTI0_HANDLER
  defisr _EXTI1_HANDLER
  defisr _EXTI2_HANDLER
  defisr _EXTI3_HANDLER
  defisr _EXTI4_HANDLER
  defisr _DMA1STREAM0_HANDLER
  defisr _DMA1STREAM1_HANDLER
  defisr _DMA1STREAM2_HANDLER
  defisr _DMA1STREAM3_HANDLER
  defisr _DMA1STREAM4_HANDLER
  defisr _DMA1STREAM5_HANDLER
  defisr _DMA1STREAM6_HANDLER
  defisr _ADC_HANDLER
  defisr _CAN1TX_HANDLER
  defisr _CAN1RX0_HANDLER
  defisr _CAN1RX1_HANDLER
  defisr _CAN1SCE_HANDLER
  defisr _EXTI95_HANDLER
  defisr _TIM1BRKTIM9_HANDLER
  defisr _TIM1UPTIM10_HANDLER
  defisr _TIM1TRGCOMTIM11_HANDLER
  defisr _TIM1CC_HANDLER
  defisr _TIM2_HANDLER
  defisr _TIM3_HANDLER
  defisr _TIM4_HANDLER
  defisr _I2C1EV_HANDLER
  defisr _I2C1ER_HANDLER
  defisr _I2C2EV_HANDLER
  defisr _I2C2ER_HANDLER
  defisr _SPI1_HANDLER
  defisr _SPI2_HANDLER
  defisr _USART1_HANDLER
  defisr _USART2_HANDLER
  defisr _USART3_HANDLER
  defisr _EXTI1510_HANDLER
  defisr _RTCALARM_HANDLER
  defisr _OTGFSWKUP_HANDLER
  defisr _TIM8BRKTIM12_HANDLER
  defisr _TIM8UPTIM13_HANDLER
  defisr _TIM8TRGCOMTIM14_HANDLER
  defisr _TIM8CC_HANDLER
  defisr _DMA1STREAM7_HANDLER
  defisr _FMC_HANDLER
  defisr _SDIO_HANDLER
  defisr _TIM5_HANDLER
  defisr _SPI3_HANDLER
  defisr _UART4_HANDLER
  defisr _UART5_HANDLER
  defisr _TIM6DAC_HANDLER
  defisr _TIM7_HANDLER
  defisr _DMA2STREAM0_HANDLER
  defisr _DMA2STREAM1_HANDLER
  defisr _DMA2STREAM2_HANDLER
  defisr _DMA2STREAM3_HANDLER
  defisr _DMA2STREAM4_HANDLER
  .word 0
  .word 0
  defisr _CAN2TX_HANDLER
  defisr _CAN2RX0_HANDLER
  defisr _CAN2RX1_HANDLER
  defisr _CAN2SCE_HANDLER
  defisr _OTGFS_HANDLER
  defisr _DMA2STREAM5_HANDLER
  defisr _DMA2STREAM6_HANDLER
  defisr _DMA2STREAM7_HANDLER
  defisr _USART6_HANDLER
  defisr _I2C3EV_HANDLER
  defisr _I2C3ER_HANDLER
  defisr _OTGHSEP1OUT_HANDLER
  defisr _OTGHSEP1IN_HANDLER
  defisr _OTGHSWKUP_HANDLER
  defisr _OTGHS_HANDLER
  defisr _DCMI_HANDLER
  .word 0
  .word 0
  defisr _FPU_HANDLER
  .word 0
  .word 0
  defisr _SPI4_HANDLER
  .word 0
  .word 0
  defisr _SAI1_HANDLER
  .word 0
  .word 0
  .word 0
  defisr _SAI2_HANDLER
  defisr _QUADSPI_HANDLER
  defisr _HDMICEC_HANDLER
  defisr _SPDIFRX_HANDLER
  defisr _FMPI2C1_HANDLER
  defisr _FMPI2C1ERROR_HANDLER

.text
.type _DEFAULT_HANDLER, %function
.global _DEFAULT_HANDLER
_DEFAULT_HANDLER:
  bkpt
  b.n _DEFAULT_HANDLER

