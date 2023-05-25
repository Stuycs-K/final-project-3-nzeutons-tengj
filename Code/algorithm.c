#include <stdio.h>
#include "methods.h"

int main()
{
    unsigned int Ms[16];
    char *fileName = "message";
    generate_Ms(fileName, Ms);

    // for(int i = 0; i < 16; i++) {
    //     printf("%x\n", Ms[i]);
    // }

    printf("\n");

    unsigned int Ks[64];
    generate_Ks(Ks);

    // for(int i = 0; i < 64; i++) {
    //     printf("%x\n", Ks[i]);
    // }

    // printf("%x\n", rotate(0b00101011110100110000100111110000, 7));

    unsigned int originalA = 19088743; // in hex: 01234567
    unsigned int originalB = 2309737967; // in hex: 89abcdef
    unsigned int originalC = 4275878552; // in hex: fedcba98
    unsigned int originalD = 1985229328; // in hex: 76543210

    printf("%x\n", F(originalB, originalC, originalD));
}
