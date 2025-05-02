#!/bin/bash

if [ -d "build" ]; then
    rm -rf build
fi
mkdir build
cd build
cmake -G "Ninja" .. -DPICO_BOARD=pico2_w
cmake --build .