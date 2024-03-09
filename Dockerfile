FROM ubuntu:22.04
ENV DEBIAN_FRONTEND noninteractive
ENV DEBCONF_NOWARNINGS yes
RUN set -x && \
  apt-get update && \
  : "basic dependencies" && \
  apt-get install -y -qq \
    cmake \
    git \
    wget \
    curl \
    tar \
    unzip \
    build-essential
#
WORKDIR /tmp
#
RUN set -x && \
   git clone https://github.com/opencv/opencv && \
   git clone https://github.com/opencv/opencv_contrib && \
   cd opencv && \
   mkdir build && cd build && \
   cmake -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules -S.. && \
   make -j$(nproc) && \
   make install





