# Work Log

## Resources
[Comparitech's MD5 Algorithm with Example](https://www.comparitech.com/blog/information-security/md5-algorithm-with-examples/)

## Skai Nzeuton

### 5/18

* Created base files
* Wrote function to parse original string input into format for later use

### 5/19

* Made slight modifications to functionality of plaintext parsing method
* algorithm.py now takes a command line argument for the name of the plaintext file to be encrypted

### 5/22

* Finished writing F, the function used in the first of four rounds
* algorithm.py loops over the function 16 times and rotates the inputs of the function

### 5/23

* Finished implementing all 64 iterations of F, G, H, I
* Added final stage of modular addition

### 5/24

* Transferred all code over to C
* algorithm.c concatenates final vectors to give final hash

## Jerry Teng
