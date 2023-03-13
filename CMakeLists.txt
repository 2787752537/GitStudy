cmake_minimum_required(VERSION 3.19)
project(c_pr C)

set(CMAKE_C_STANDARD 99)

add_executable(c_pr main.c 1/text1.3.c 1/text1.3.h 2/symbolic.h 2/symbolic.c 3/operator.h 3/operator.c 4/cycle.c 4/cycle.h 5/array.c 5/array.h)