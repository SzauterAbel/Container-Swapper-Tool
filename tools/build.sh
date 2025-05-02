#!/usr/bin/env bash

TOOLS_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
ROOT_DIR="$TOOLS_DIR/.."
SRC_DIR="$ROOT_DIR/src"
BUILD_DIR="$ROOT_DIR/build"

function build {
    cmake -S "$SRC_DIR" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Debug
    cmake --build "$BUILD_DIR"
}

build