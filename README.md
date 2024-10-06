# ARM-ASSEMBLY

[![GitHub tag (with filter)](https://img.shields.io/github/v/tag/PanBabinicz/arm_assembly?style=plastic&label=latest)](https://github.com/PanBabinicz/arm_assembly/releases/latest)

## ❓ What is ARM-ASSEMBLY for?

> You can find examples written in assemlby for ARM based processors here as
> well as main drivers implementation such as I2C, SPI and UART.

> [!NOTE]
> **Please bear in mind that the workspace was primarily created for enjoyment
> and educational endeavors.**

## Usage

> **debugger**  - arm-none-eabi-gdb <binary>
> **openOCD**   - openocd -f <interface-config> -f <board-config>
> **assembler** - arm-none-eabi-as -g -I <include-path> <source-file> -o <object-file>
> **linker**    - arm-none-eabi-ld <object-files> -o <binary-file> -T <linkerscript>
