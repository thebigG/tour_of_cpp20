FROM ubuntu:21.10
USER root
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y g++-11 \
                                         git \
                                         make \
                                         build-essential \
                                         clang-format \
                                         cmake \
                                         valgrind \
                                         vim \
                                         lcov

RUN git clone https://github.com/thebigG/Catch2.git
RUN cd Catch2 \
    && cmake -Bbuild -H. -DBUILD_TESTING=OFF  \
    && cmake --build build/ --target install
RUN rm -r Catch2

