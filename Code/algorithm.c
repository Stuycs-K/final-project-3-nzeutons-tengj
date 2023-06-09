#include <stdio.h>
#include "methods.h"

int main(int argc, char *argv[]) {
    if(argc == 2 || argc == 3) {
        unsigned int Ms[16];
        char *fileName = argv[1];
        generate_Ms(fileName, Ms);

        unsigned int Ks[64];
        generate_Ks(Ks);

        unsigned int originalA = 0x67452301;
        unsigned int originalB = 0xefcdab89;
        unsigned int originalC = 0x98badcfe;
        unsigned int originalD = 0x10325476;

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

            result = (result + vectors[0]);
            result = (result + Ms[k]);
            result = (result + Ks[i]);
            result = rotate(result, shifts[i % 4]);
            result = (result + vectors[1]);

            vectors[0] = vectors[3];
            vectors[3] = vectors[2];
            vectors[2] = vectors[1];
            vectors[1] = result;
        }

        vectors[0] = (vectors[0] + originalA);
        vectors[1] = (vectors[1] + originalB);
        vectors[2] = (vectors[2] + originalC);
        vectors[3] = (vectors[3] + originalD);

        if(argc == 3) {
            FILE *fp = fopen(argv[2], "w");
            for(int j = 0; j < 4; j++) {
                for(int i = 0; i < 4; i++) {
                    fprintf(fp, "%02x", (vectors[j] << (24 - 8*i)) >> 24);
                }
            }

            fclose(fp);
        }
        else {
            for(int i = 0; i < 4; i++) {
                printLittleEndian(vectors[i]);
            }
            printf("\n");
        }

    }
    else {
        printf("Please provide only an input file name and an optional output file name.\n");
    }
}
