        .syntax unified
        .cpu cortex-m4
        .thumb

        .macro defisr name
            .type \name, %function
            .global \name
            .weak \name
            .thumb_set \name, _default_handler
            .word \name
        .endm

        .text
        .global _vector_table
        .section ._vector_table, "a"
        .type _vector_table, %object
_vector_table:
        .word _stack_end
        defisr _reset_handler
        defisr _nmi_handler
        defisr _hardfault_handler
        defisr _memmanage_handler
        defisr _busfault_handler
        defisr _usagefault_handler
        .word 0
        .word 0
        .word 0
        .word 0
        defisr _svcall_handler
        defisr _debugmonitor_handler
        .word 0
        defisr _pendsv_handler
        defisr _systick_handler
        defisr _wwdg_handler
        defisr _pvd_handler
        defisr _tampstamp_handler
        defisr _rtcwkup_handler
        defisr _flash_handler
        defisr _rcc_handler
        defisr _exti0_handler
        defisr _exti1_handler
        defisr _exti2_handler
        defisr _exti3_handler
        defisr _exti4_handler
        defisr _dma1stream0_handler
        defisr _dma1stream1_handler
        defisr _dma1stream2_handler
        defisr _dma1stream3_handler
        defisr _dma1stream4_handler
        defisr _dma1stream5_handler
        defisr _dma1stream6_handler
        defisr _adc_handler
        defisr _can1tx_handler
        defisr _can1rx0_handler
        defisr _can1rx1_handler
        defisr _can1sce_handler
        defisr _exti95_handler
        defisr _tim1brktim9_handler
        defisr _tim1uptim10_handler
        defisr _tim1trgcomtim11_handler
        defisr _tim1cc_handler
        defisr _tim2_handler
        defisr _tim3_handler
        defisr _tim4_handler
        defisr _i2c1ev_handler
        defisr _i2c1er_handler
        defisr _i2c2ev_handler
        defisr _i2c2er_handler
        defisr _spi1_handler
        defisr _spi2_handler
        defisr _usart1_handler
        defisr _usart2_handler
        defisr _usart3_handler
        defisr _exti1510_handler
        defisr _rtcalarm_handler
        defisr _otgfswkup_handler
        defisr _tim8brktim12_handler
        defisr _tim8uptim13_handler
        defisr _tim8trgcomtim14_handler
        defisr _tim8cc_handler
        defisr _dma1stream7_handler
        defisr _fmc_handler
        defisr _sdio_handler
        defisr _tim5_handler
        defisr _spi3_handler
        defisr _uart4_handler
        defisr _uart5_handler
        defisr _tim6dac_handler
        defisr _tim7_handler
        defisr _dma2stream0_handler
        defisr _dma2stream1_handler
        defisr _dma2stream2_handler
        defisr _dma2stream3_handler
        defisr _dma2stream4_handler
        .word 0
        .word 0
        defisr _can2tx_handler
        defisr _can2rx0_handler
        defisr _can2rx1_handler
        defisr _can2sce_handler
        defisr _otgfs_handler
        defisr _dma2stream5_handler
        defisr _dma2stream6_handler
        defisr _dma2stream7_handler
        defisr _usart6_handler
        defisr _i2c3ev_handler
        defisr _i2c3er_handler
        defisr _otghsep1out_handler
        defisr _otghsep1in_handler
        defisr _otghswkup_handler
        defisr _otghs_handler
        defisr _dcmi_handler
        .word 0
        .word 0
        defisr _fpu_handler
        .word 0
        .word 0
        defisr _spi4_handler
        .word 0
        .word 0
        defisr _sai1_handler
        .word 0
        .word 0
        .word 0
        defisr _sai2_handler
        defisr _quadspi_handler
        defisr _hdmicec_handler
        defisr _spdifrx_handler
        defisr _fmpi2c1_handler
        defisr _fmpi2c1error_handler

        .text
        .type _default_handler, %function
        .global _default_handler
_default_handler:
        bkpt
        b.n _default_handler

        .end
