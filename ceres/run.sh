#!/bin/bash

set -e 

mkdir -p build
cd build
cmake ..
make -j2

./example_1

