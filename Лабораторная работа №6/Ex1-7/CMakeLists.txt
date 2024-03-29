cmake_minimum_required(VERSION 3.26)
project(Ex1_7 C)

set(CMAKE_C_STANDARD 11)

add_executable(Ex1_7 main.c
        Functions.h
        arr.c
        merge_sort_posotive_elements.c
        output.c
        bigarr.c
        buble_sort.c
        time_manage.c)
