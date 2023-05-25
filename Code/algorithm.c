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

    for(int i = 0; i < 64; i++) {
        unsigned int M = Ms[i % 16];

        if(i < 16) {
            int shifts[4] = {7, 12, 17, 22};

            result = F(vectors[1], vectors[2], vectors[3]);

            result = (result + vectors[0]) % (unsigned int) pow(2, 32);
            result = (result + M) % (unsigned int) pow(2, 32);
            result = (result + Ks[i]) % (unsigned int) pow(2, 32);
            result = rotate(result, shifts[i % 4]);
            result = (result + vectors[1]) % (unsigned int) pow(2, 32);

            if(i == 0) {
                printf("%x\n", result);
            }
        }
        else if(i < 32) {

        }
        else if(i < 48) {

        }
        else {

        }
    }

    // printf("%x\n", F(originalB, originalC, originalD));

    // unsigned int A = 2040337234; // 799d1352
    // unsigned int B = 741662626; // 2c34dfa2
    // unsigned int C = 3726013374; // de1673be
    // unsigned int D = 1268212354; // 4b976282

    // printf("%x\n", G(B, C, D));

    // A = 3944090832; // eb160cd0
    // B = 3574010727; // d5071367
    // C = 3227037154; // c058ade2
    // D = 1673921495; // 63c603d7

    // printf("%x\n", H(B, C, D));

    // A = 1624100529; // 60cdceb1
    // B = 2102403171; // 7d502063
    // C = 2336059741; // 8b3d715d
    // D = 501458745; // 1de3a739

    // printf("%x\n", I(B, C, D));
}
