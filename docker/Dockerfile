FROM ubuntu:22.04

RUN mkdir -p /home/container_swapper/src \
    /home/container_swapper/build \
    /home/container_swapper/tools

ARG USER_ID=1000
ARG GROUP_ID=1000

RUN groupadd -g $GROUP_ID user && \
    useradd -m -u $USER_ID -g $GROUP_ID user

ENV CC="/usr/bin/clang-14" \
    CXX="/usr/bin/clang++-14" \
    LDFLAGS="-L/usr/lib/llvm-14/lib" \
    CXXFLAGS="-I/usr/lib/llvm-14/include -frtti"

COPY entrypoint.sh /home/container_swapper/entrypoint.sh

RUN apt-get update &&  apt-get install -y clang-14 llvm-14 libclang-14-dev cmake git

USER user
WORKDIR /home/container_swapper/

ENTRYPOINT ["/home/container_swapper/entrypoint.sh"]
CMD ["/bin/bash"]