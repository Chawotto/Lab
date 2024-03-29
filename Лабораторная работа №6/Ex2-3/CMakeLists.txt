cmake_minimum_required(VERSION 3.26)
project(Ex2_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Ex2_3 main.c
        Functions.h
        arr.c
        output.c
        input_sort.c
)
