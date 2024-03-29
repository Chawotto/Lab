cmake_minimum_required(VERSION 3.26)
project(lab7 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab7 main.c
                taskSelection.c
                taskSelection.h
                task1.c
                task1.h
                task2.c
                task2.h
                task3.c
                task3.h
        longword.c
        NewString.c
        Merge_Sort.c
)
