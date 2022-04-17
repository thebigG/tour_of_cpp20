#!/bin/bash
cd tests/build
lcov -c -i -b modules/ -d modules/ -o Coverage.baseline
./test
lcov -c -d . -b modules -o Coverage.out
lcov -a Coverage.baseline -a Coverage.out -o Coverage.combined
lcov -r Coverage.combined /usr/include/\* -o Coverage.combined
lcov -r Coverage.combined *main.cpp* -o Coverage.combined
genhtml Coverage.combined -o HTML
