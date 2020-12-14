#!/bin/bash

set -euo pipefail

CC=gcc
Formater=clang-format

install_complier() {
    if [[ ! -x "$(command -v ${CC})" ]]; then
        echo "${CC} is not installed, install now."
        sudo apt install -y ${CC}
    fi
}

install_formater() {
    if [[ ! -x "$(command -v ${Formater})" ]]; then
        echo "${Formater} is not installed, install now."
        sudo apt install -y ${Formater}
    fi
}

main() {
    install_complier
    install_formater
}

main "$@"
