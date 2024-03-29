#include <stdlib.h>
#include <stdio.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

void taskSelection (int argc, char** argv){

    void (*taskfunc)(int, char**) = NULL;

    switch (argv[1][0])
    {
        case '1':
            taskfunc = task1;
            break;

        case '2':
            taskfunc = task2;
            break;

        case '3':
            taskfunc = task3;
            break;

        default:
            printf("No arguments provided.n");
            return;
    }
    taskfunc(argc, argv);
}