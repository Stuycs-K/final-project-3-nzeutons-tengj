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
#### Padding
Before generating M's, though, we may need to apply padding to our input. MD5's inputs are broken up into 512-bit blocks, and padding is utilized to fill up any potential empty space in a block. For example, consider an input that is 256 bits. To meet the required 512-bit block, the MD5 algorithm adds a 1, then enough 0s to reach 448 bits; in this case, the padding succeeding our input would be a one, followed by 191 zeros. 

But what about the last 64 bits? The algorithm reserves these bits to display the message's length in binary in the final block; 200 in binary would be 11001000, so the last 8 bits of the block would be replaced with that, while the 56 bits in between are filled up with zeros.

##### Padding with inputs greater than 448 bits
If our input is greater than 448 bits, then it would be split between multiple blocks. The last block, however, must have at least 1 bit of padding, in addition to the 64 bits at the end reserved for the message's length in binary. 

If our remaining input was 447 bits, then the last block would be the last 447 bits, followed by a 1 and then the reserved 64 bits. 

If our remaining input was exactly 448 bits, we would need instead need two blocks, as a single block would not be able to fit 448 bits alongside the required padding and binary message display; the second-to-last block would have the 448 bits, then a 1 followed by 63 zeros. The padding would extend to the 448th bit of the last block, totaling to 512 bits of padding. 

If our remaining input was 449 bits, the second-to-last block would have these 449 bits, followed by a 1 and 62 zeros; the last block would contain 448 zeros, followed by the 64-bit message length.

#### The M input
Now that our initial input has padding, we can start generating our M's. The algorithm takes each 512-bit block, and splits them into 16 32-bit "M values"; let's refer to them as M0, M1, M2, all the way to M15. After converting these values to hexadecimal, these 16 values become the inputs to the respective 16 operations in each round. In each round however, the M values are added in a different order:

First round: M0, M1, M2, M3, M4, M5, M6, M7, M8, M9, M10, M11, M12, M13, M14, M15
Second round: M1, M6, M11, M0, M5, M10, M15, M4, M9, M14, M3, M8, M13, M2, M7, M12
Third round: M5, M8, M11, M14, M1, M4, M7, M10, M13, M0, M3, M6, M9, M12, M15, M2
Fourth round: M0, M7, M14, M5, M12, M3, M10, M1, M8, M15, M6, M13, M4, M11, M2, M9

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
5. Adding the result of the previous operation (B)
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
