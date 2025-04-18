#!/bin/bash

cmake --build build/debug
echo "=========================================="
./build/debug/src/cli/YunittoCLI
