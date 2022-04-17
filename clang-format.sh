#!/usr/bin/env bash
clang-format -i -style=file src/*
clang-format -i -style=file tests/*.cpp
