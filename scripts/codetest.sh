#!/bin/bash

set -euo pipefail

current_dir() {
    # absolute path
    dir=$(cd $(dirname $0) && pwd)
    cd ${dir}
}

main() {
    current_dir
    cd ../test
    files=$(ls *.c)
    for file in ${files[@]}; do
        echo "+ ${file}"
        gcc ${file} ../src/*.c -I../include
        ./a.out
    done
    rm ./a.out
}

main "$@"
