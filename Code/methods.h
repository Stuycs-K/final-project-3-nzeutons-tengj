#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <math.h>

void generate_Ms(char *fileName, unsigned int *Ms);
void generate_Ks(unsigned int *Ks);
unsigned int rotate(unsigned int num, int shift);

unsigned int F(unsigned int B, unsigned int C, unsigned int D);
unsigned int G(unsigned int B, unsigned int C, unsigned int D);
unsigned int H(unsigned int B, unsigned int C, unsigned int D);
unsigned int I(unsigned int B, unsigned int C, unsigned int D);
