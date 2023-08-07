#!/bin/bash

clang-format --Werror -style=Google -n $(find src/cat src/grep -name '*.c' -o -name '*.h')
