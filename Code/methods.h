#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

unsigned int* generate_Ms(char *str, unsigned int *Ms);
unsigned int* generate_Ks(unsigned int *Ks);
unsigned int rotate(unsigned int num, int shift);

unsigned int F(unsigned int B, unsigned int C, unsigned int D);
unsigned int G(unsigned int B, unsigned int C, unsigned int D);
unsigned int H(unsigned int B, unsigned int C, unsigned int D);
unsigned int I(unsigned int B, unsigned int C, unsigned int D);
