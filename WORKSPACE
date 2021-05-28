workspace(name = "chibios-bazel")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "bazel_embedded",
    commit = "14d51da3c1de4c7b8b7ce78e87e4f25d9802bee4",
    remote = "https://github.com/silvergasp/bazel-embedded.git",
    shallow_since = "1616471159 +0800"
)

load("@bazel_embedded//:bazel_embedded_deps.bzl", "bazel_embedded_deps")

bazel_embedded_deps()

load("@bazel_embedded//platforms:execution_platforms.bzl", "register_platforms")

register_platforms()

load(
    "@bazel_embedded//toolchains/compilers/gcc_arm_none_eabi:gcc_arm_none_repository.bzl",
    "gcc_arm_none_compiler",
)

gcc_arm_none_compiler()

load("@bazel_embedded//toolchains/gcc_arm_none_eabi:gcc_arm_none_toolchain.bzl", "register_gcc_arm_none_toolchain")

register_gcc_arm_none_toolchain()

load("@bazel_embedded//tools/openocd:openocd_repository.bzl", "openocd_deps")

openocd_deps()

http_archive(
    name = "chibios",
    url = "https://github.com/ChibiOS/ChibiOS/archive/refs/tags/ver20.3.3.tar.gz",
    sha256 = "e6e5cafa5a74346e20ad5fc735d424a073856a0ecb6d32f4a81a477e501c15e7",
    build_file = "@//example:chibios.BUILD",
    strip_prefix = "ChibiOS-ver20.3.3",
)
