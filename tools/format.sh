#!/usr/bin/env bash

TOOLS_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
ROOT_DIR="$TOOLS_DIR/.."
SRC_DIR="$ROOT_DIR/src"

function format() {
    find $SRC_DIR -iname '*.h' -o -iname '*.cpp' -o -iname "*.hpp" | xargs clang-format -i --verbose
    find $SRC_DIR -name 'CMakeLists.txt' | xargs cmake-format -i --log-level debug
}

format