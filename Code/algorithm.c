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

    unsigned int vectors[4] = {originalA, originalB, originalC, originalD};

    unsigned int result;
    int shifts[4];
    int k;

    for(int i = 0; i < 64; i++) {
        if(i < 16) {
            shifts[0] = 7;
            shifts[1] = 12;
            shifts[2] = 17;
            shifts[3] = 22;
            result = F(vectors[1], vectors[2], vectors[3]);
            k = i;
        }
        else if(i < 32) {
            shifts[0] = 5;
            shifts[1] = 9;
            shifts[2] = 14;
            shifts[3] = 20;
            result = G(vectors[1], vectors[2], vectors[3]);
            k = (5*(i + 1 % 16) - 4) % 16;
        }
        else if(i < 48) {
            shifts[0] = 4;
            shifts[1] = 11;
            shifts[2] = 16;
            shifts[3] = 23;
            result = H(vectors[1], vectors[2], vectors[3]);
            k = (3*(i + 1 % 16) + 2) % 16;
        }
        else {
            shifts[0] = 6;
            shifts[1] = 10;
            shifts[2] = 15;
            shifts[3] = 21;
            result = I(vectors[1], vectors[2], vectors[3]);
            k = 7*(i % 16) % 16;
        }

        result = (result + vectors[0]) % (unsigned int) pow(2, 32);
        // printf("%d\n", k);
        result = (result + Ms[k]) % (unsigned int) pow(2, 32);
        result = (result + Ks[i]) % (unsigned int) pow(2, 32);
        result = rotate(result, shifts[i % 4]);
        result = (result + vectors[1]) % (unsigned int) pow(2, 32);
        
        vectors[0] = vectors[3];
        vectors[3] = vectors[2];
        vectors[2] = vectors[1];
        vectors[1] = result;
    }

    vectors[0] = (vectors[0] + originalA) % (unsigned int) pow(2, 32);
    vectors[1] = (vectors[1] + originalB) % (unsigned int) pow(2, 32);
    vectors[2] = (vectors[2] + originalC) % (unsigned int) pow(2, 32);
    vectors[3] = (vectors[3] + originalD) % (unsigned int) pow(2, 32);

    for(int i = 0; i < 4; i++) {
        printf("%x\n", vectors[i]);
    }

    printf("\n");

    for(int i = 0; i < 4; i++) {
        printf("%x", vectors[i]);
    }
    printf("\n");
}
