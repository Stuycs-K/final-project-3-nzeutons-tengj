# MD5 Algorithm Implemented in C

## What is MD5?  
MD5 is a hash function invented by Ronald Rivest (MIT) in 1991 to replace his older hash function, MD4.  
A hash function is a function that takes an input value and generates fixed-length output values to represent the original input.  
They are generally used for encryption, data compression, and generating indices.

MD5 was designed for data security and encryption, but today its primary use is being a checksum to verify data integrity against unintentional corruption.  

This is because it is no longer secure due to the fact that a tampered file could have the same exact hash as the original file.  
This makes it impossible to be certain that the file is actually secure or not.  

Because of this, most security experts recommend that MD5 should be replaced with SHA-2.

## The MD5 Process
<img class="img-fluid" src="Pictures/full_algorithm.jpg" alt="img-verification" height="900px">

MD5 has 4 major stages:
1. Generating M's
2. Initialization vectors + Operations
3. Final modular addition
4. Concatenating final results

### I. Generating M's


### II. Initialization vectors + Operations
#### Initialization vectors
The initialization vectors are the values that are going to be continuously modified throughout the MD5 algorithm.  
The initial vectors are given to us and stored as A, B, C, and D.  
```
A = 0x67452301
B = 0xefcdab89
C = 0x98badcfe
D = 0x10325476
```

#### Operations
The operations are the process by which the initialization vectors are transformed into the hash.  

<img class="img-fluid" src="Pictures/operation.jpg" alt="img-verification" height="400px">

Each operation has 6 parts:
1. Boolean algebra function (F, G, H, I)
2. Adding M<sub>i</sub>
3. Adding K<sub>i</sub>
4. Hash rotation
5. Adding the result of the previous operation
6. Vector rotation

Operations are performed a total of 64 times throughout the algorithm.  
Each operation uses a different value for M<sub>i</sub> and K<sub>i</sub>.  
The boolean algebra function and hash rotation scheme change every 16 operations.

**Boolean algebra function (F, G, H, I)**  
The first part of each operation is the boolean algebra function.  
This function creates a result by performing boolean algebra on initialization vectors B, C, and D.  

Boolean algebra is a branch of mathematics that deals with operations on logical values.  
For MD5, we use 4 logical operators:
1. ∧ AND
2. ∨ OR
3. ¬ NOT
4. ⊕ XOR

MD5 uses 4 boolean algebra functions:
1. F: (B∧C)∨(¬B∧D) = `(B&C) | (~B|D)`
2. G: (B∧D)∨(C∧¬D) =  `(B&D) | (C&~D)`
3. H: B⊕C⊕D = `B ^ C ^ D`
4. I: C⊕(B∨¬D) = `C ^ (B|~D)`

F is used for operations 1-16  
G is used for operations 17-32  
H is used for operations 33-48  
I is used for operations 49-64

### III. Final modular addition


### IV. Concatenating final results
