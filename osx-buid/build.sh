#!/usr/bin/env bash

# Run in the parent directory of the script
# This is needed to be able to run the script from any directory
cd "$(dirname "$0")/.."

rm -rf build
mkdir build
cd build

cmake .. -DMARCH=armv8-a
