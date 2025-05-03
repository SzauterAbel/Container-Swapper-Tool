#!/usr/bin/env bash

TOOLS_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
ROOT_DIR="$TOOLS_DIR/.."
SRC_DIR="$ROOT_DIR/src"
BUILD_DIR="$ROOT_DIR/build"
DOCKER_DIR="$ROOT_DIR/docker"
CURRENT_DIR="$PWD"
IMAGE_NAME="container-swapper"

function build_tool {
    cd $DOCKER_DIR

    echo "Building docker image"
    docker build -t $IMAGE_NAME .

    echo "Starting container"
    CONTAINER_ID=$(docker run -dit \
    -v $SRC_DIR:/home/container_swapper/src \
	-v $TOOLS_DIR:/home/container_swapper/tools \
	-v $BUILD_DIR:/home/container_swapper/build \
	--rm $IMAGE_NAME)

    echo "Building tool in container"
    docker exec "$CONTAINER_ID" ./tools/build.sh -d

    echo "Stopping container"
    docker stop "$CONTAINER_ID"

    cd $CURRENT_DIR
}

build_tool