#!/bin/bash

set -euo pipefail

current_dir() {
    # absolute path
    dir=$(cd $(dirname $0) && pwd)
    cd ${dir}
}

clean_include() {
    rm -rf ../include
    mkdir -p ../include
}

generate_include() {
    cd ../src
    for header in $(ls *.h); do
        echo "#include \"../src/${header}\"" > ../include/${header}
    done
}

main() {
    current_dir
    clean_include
    generate_include
}

main "$@"
