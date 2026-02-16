FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y git curl python3 xz-utils bzip2 libatomic1
WORKDIR /opt
RUN curl -L https://github.com/YosysHQ/oss-cad-suite-build/releases/download/2026-02-16/oss-cad-suite-linux-x64-20260216.tgz | tar zxf -
RUN git clone --depth 1 https://github.com/emscripten-core/emsdk.git
WORKDIR /opt/emsdk
RUN ./emsdk install latest && ./emsdk activate latest

RUN adduser --disabled-password --gecos "" wokwi
USER wokwi
ENV PATH="/opt/oss-cad-suite/bin:${PATH}"
ADD --chown=wokwi project /home/wokwi/project
WORKDIR /home/wokwi/project
VOLUME /home/wokwi/project

# Wokwi builder configuration:
ENV HEXI_SRC_DIR="/home/wokwi/project/src"
ENV HEXI_BUILD_CMD="/home/wokwi/project/compile.sh"
ENV HEXI_OUT_HEX="/home/wokwi/project/chip.wasm"
ENV HEXI_OUT_ELF="/home/wokwi/project/chip.wasm"

CMD [ "bash", "./compile.sh" ]


