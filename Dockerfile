FROM gcc:12

LABEL description="Development image for Advent of Code"

RUN apt-get update 
RUN apt-get upgrade -y
RUN apt-get install -y libgtest-dev \
                   cmake 
