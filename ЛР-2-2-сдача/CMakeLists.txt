cmake_minimum_required(VERSION 3.26)
project(_2_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(_2_2 main.c
        "task 1.c"
        "task 2.c"
        "task 2.h"
        "task 1.h"
        GenFunc.c
        GenFunc.h
)
