#include <stdlib.h>
#include "task1.h"

void task1 (int argc, char** argv) {
    int len = myStrLen(argv[2]);
    printLongestWord(argv[2], len);
    exit(1);
}