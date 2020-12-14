#!/bin/bash

set -euo pipefail

current_dir() {
    # absolute path
    dir=$(cd $(dirname $0) && pwd)
    cd ${dir}
}

format_src() {
    clang-format -i  ../src/*.h
    clang-format -i  ../src/*.c
}

format_include() {
    clang-format -i  ../include/*.h
}

format_test() {
    clang-format -i  ../test/*.c
}

format_examples() {
    clang-format -i  ../examples/*.c
}

main() {
    current_dir
    format_src
    format_include
    format_test
    format_examples
}

main "$@"
