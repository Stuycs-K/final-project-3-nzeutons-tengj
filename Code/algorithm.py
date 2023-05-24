import sys
from methods import *

fileName = sys.argv[1]

originalA = 19088743; # in hex: 01234567
originalB = 2309737967; # in hex: 89abcdef
originalC = 4275878552; # in hex: fedcba98
originalD = 1985229328; # in hex: 76543210

f = open(fileName, "r")
message = f.read()

Ms = generate_Ms(message)

# for M in Ms:
#     print(hex(M))

Ks = generate_Ks()

# for K in Ks:
#     print(hex(K))

vectors = []

for i in range(16):
    if(i == 0):
        vectors = F(originalA, originalB, originalC, originalD, Ms[i], Ks[i], 7 + 5*(i % 4))
    else:
        vectors = F(vectors[3], vectors[0], vectors[1], vectors[2], Ms[i], Ks[i], 7 + 5*(i % 4))

# for vector in vectors:
#     print(hex(vector))

# A = 2040337234 # 799d1352
# B = 741662626 # 2c34dfa2
# C = 3726013374 # de1673be
# D = 1268212354 # 4b976282

print("")

shifts = [5, 9, 14, 20]

for i in range(16):
    if(i == 0):
        vectors = G(vectors[0], vectors[1], vectors[2], vectors[3], Ms[i], Ks[i + 16], shifts[i % 4])
    else:
        vectors = G(vectors[3], vectors[0], vectors[1], vectors[2], Ms[i], Ks[i + 16], shifts[i % 4])
    
# for vector in vectors:
#     print(hex(vector))

A = 3944090832 # eb160cd0
B = 3574010727 # d5071367
C = 3227037154 # c058ade2
D = 1673921495 # 63c603d7

shifts = [4, 11, 16, 13]

for i in range(16):
    if(i == 0):
        vectors = H(vectors[0], vectors[1], vectors[2], vectors[3], Ms[i], Ks[i + 32], shifts[i % 4])
    else:
        vectors = H(vectors[3], vectors[0], vectors[1], vectors[2], Ms[i], Ks[i + 32], shifts[i % 4])

for vector in vectors:
    print(hex(vector))