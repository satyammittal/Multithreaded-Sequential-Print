# Installation

cmake .
make
./output <string> <p> <k> <n>

p: number of threads
k: number of times to print
n: length of substring

# Test files

`tests/stress_test.txt`
`tests/manual_test.txt`

# How to test

./tests/run.sh tests/manual_test.txt
./tests/run.sh tests/stress_test.txt

To generate more tests,

g++ -std=c++11 tests/test.cpp
./a.out > testfile
