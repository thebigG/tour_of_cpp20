FROM ubuntu:21.10
USER root
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y g++-11 \
                                         git \
                                         make \
                                         build-essential \
                                         clang-format
