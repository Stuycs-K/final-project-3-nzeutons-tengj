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

### 5/25

* Added debugging print statements
* Changed initialization vectors and trying to cross reference with other implementations

### 5/28

* Fixed algorithm by changing padding to little endian
* algorithm.c only prints the hash now
* Hash is formatted for little endian
* algorithm.c takes command line argument for which file it should encrypt

### 5/30

* Updated README.md

## Jerry Teng

### 5/18

* Created algorithm.py\/methods.py

### 5/19

* Created initilizaiton vectors in algorithm.py (put the hexadecimal equivalents as a comment)

### 5/22

* Working on coding function F, and on generating M and K values

### 5/23

* Implementing modular addition, continuing on the other functions

### 5/24

* Tried in class to convert to convert python files to java, agreed to instead change methods\/algorithms to be coded in C
