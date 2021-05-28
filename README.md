# ChibiOS / Bazel Example

This repository contains a skeleton project that integrates [ChibiOS](https://www.chibios.org/dokuwiki/doku.php) with [Bazel](https://bazel.build/) using the [bazel-embedded](https://github.com/silvergasp/bazel-embedded) for an STM32F4 target.

The board/configuration files are based on the `RT-STM32F469I-DISCOVERY` files form ChibiOS source tree.

## Prerequisites
You'll need to have `bazel` on your machine. It's recommended to use [bazelisk](https://github.com/bazelbuild/bazelisk) so that it can automatically load the correct version of `bazel` (from `.bazelversion`).

This has only been tested in a Linux environment (specifically Ubuntu 20.04)

## To build the example
```bash
build //example --platforms=@bazel_embedded//platforms:cortex_m4_fpu
```

You'll end up with a binary at `bazel-bin/example/example`
```
$ readelf -h bazel-bin/example/example
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           ARM
  Version:                           0x1
  Entry point address:               0x8000241
  Start of program headers:          52 (bytes into file)
  Start of section headers:          151988 (bytes into file)
  Flags:                             0x5000400, Version5 EABI, hard-float ABI
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         4
  Size of section headers:           40 (bytes)
  Number of section headers:         34
  Section header string table index: 33
```

## How to adapt this for your own project
You'll have to modify the following files:
* `board.h` - board-specific configuration
* `chconf.h` - ChibiOS configuration options
* `halconf.h` - ChibiOS/HAL configuration options
* `STM32F4.ld` - Linker script
