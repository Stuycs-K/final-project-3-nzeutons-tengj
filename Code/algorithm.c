#include <stdio.h>
#include "methods.h"

int main()
{
    unsigned int Ms[16];
    char *fileName = "message";
    generate_Ms(fileName, Ms);

    for(int i = 0; i < 16; i++) {
        printf("%x\n", Ms[i]);
    }
}
