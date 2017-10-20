#!/bin/bash
set -e
mkdir -p build
cd build; cmake ..; make -j8
./klt_test

