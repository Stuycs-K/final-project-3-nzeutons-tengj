#include <stdio.h>
#include "methods.h"

void generate_Ms(char *fileName, unsigned int *Ms) {
    int fd = open(fileName, O_RDONLY);
    if(fd == -1) {
        printf("%s\n", strerror(errno));
    }

    struct stat stat_buffer;
    stat(fileName, &stat_buffer);
    int str_len = stat_buffer.st_size;

    int str_index = 0;
    for(int i = 0; i < 16; i++) {
        if(i == 14) {
            Ms[i] = 0;
        }
        else if(i == 15) {
            Ms[i] = 8 * str_len;
        }
        else {
            unsigned int M = 0;

            if(str_index < str_len) {
                for(int j = 0; j < 4; j++) {
                    char chr = 0;
                    read(fd, &chr, sizeof(char));
                    if(str_index < str_len) {
                        M = M | (chr << (24 - 8*(str_index % 4)));
                        if(str_index + 1 == str_len) {
                            if((str_index + 1) % 4 > 0) {
                                M = M | (1 << (23 - 8*(str_index % 4)));
                            }
                        }
                    }

                    str_index++;
                }
            }
            else if(str_index == str_len) {
                M = 1 << 31;
                str_index++;
            }

            Ms[i] = M;
        }
    }

    close(fd);
}

void generate_Ks(unsigned int *Ks) {
    for(int i = 0; i < 64; i++) {
        Ks[i] = (unsigned int) (fabs(sin(i + 1)) * pow(2, 32));
    }
}

unsigned int rotate(unsigned int num, int shift) {
    return (num << shift) | (num >> (32 - shift));
}

unsigned int F(unsigned int B, unsigned int C, unsigned int D) {
    return (B & C) | ((~B) & D);
}

unsigned int G(unsigned int B, unsigned int C, unsigned int D) {
    return (B & D) | (C & (~D));
}

unsigned int H(unsigned int B, unsigned int C, unsigned int D) {
    return B ^ C ^ D;
}

unsigned int I(unsigned int B, unsigned int C, unsigned int D) {
    return C ^ (B | (~D));
}