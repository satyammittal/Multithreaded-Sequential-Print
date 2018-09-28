# Multithreaded-Sequential-Print

Program which prints string sequentially in k iterations among n threads.

# Principles Used

a) Mutual Exclusion

b) Starvation Prevention

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

# References

a) https://www.youtube.com/watch?v=LL8wkskDlbs&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=1

b) http://www.acodersjourney.com/2017/08/top-20-cplusplus-multithreading-mistakes/
