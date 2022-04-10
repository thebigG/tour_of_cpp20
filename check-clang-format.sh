#!/usr/bin/env bash
clang-format --dry-run --Werror -style=file src/* && clang-format --dry-run --Werror -style=file tests/*.cpp 
exit $?
