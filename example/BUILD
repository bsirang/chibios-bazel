load("@bazel_embedded//tools/openocd:defs.bzl", "openocd_debug_server", "openocd_flash")

exports_files([
    "STM32F4.ld",
    "board.h",
    "board.c",
])

cc_binary(
    name = "example",
    srcs = [
        "main.cc",
    ],
    copts = [
        "-mthumb",
        "-Iexample/cfg",
        "-Iexample",
    ],
    linkopts = [
        "-lstdc++",
    ],
    deps = [
        "@chibios",
    ],
)

cc_library(
    name = "cfg",
    hdrs = [
        "@//example:board.h",
        "@//example/cfg:halconf.h",
        "@//example/cfg:mcuconf.h",
    ],
)

openocd_flash(
    name = "flash",
    device_configs = [
        "target/stm32f4x.cfg",
    ],
    image = ":example.stripped",
    interface_configs = [
        "interface/stlink.cfg",
    ],
    transport = "hla_swd",
)
