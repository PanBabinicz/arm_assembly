# ARM-ASSEMBLY

[![GitHub tag (with filter)](https://img.shields.io/github/v/tag/PanBabinicz/arm_assembly?style=plastic&label=latest)](https://github.com/PanBabinicz/arm_assembly/releases/latest)

## ❓ What is ARM-ASSEMBLY for?

> You can find examples written in assemlby for ARM based processors here as
> well as main drivers implementation such as I2C, SPI and UART.

> [!NOTE]
> **Please bear in mind that the workspace was primarily created for enjoyment
> and educational endeavors.**

## Usage

> **debugger**  - arm-none-eabi-gdb "binary"

> **openOCD**   - openocd -f "interface-config" -f "board-config"

> **assembler** - arm-none-eabi-as -g -I "include-path" "source-file" -o "object-file"

> **linker**    - arm-none-eabi-ld "object-files" -o "binary-file" -T "linkerscript"

## License

> The MIT License (MIT)
>
> Copyright (c) 2011-2024 The Bootstrap Authors
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in
> all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
> THE SOFTWARE.
