#syntax=docker/dockerfile:1

FROM ubuntu:24.04

WORKDIR /src/app/

RUN apt update
RUN apt install cmake gcc -y

COPY ./CMakeLists.txt /src/app/CMakeLists.txt
COPY ./src/ /src/app/src/
COPY ./program_build_and_execution.sh /src/app/program_build_and_execution.sh

CMD ./program_build_and_execution.sh
