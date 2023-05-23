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

# print()

# vectors = F(originalA, originalB, originalC, originalD, Ms[0], Ks[0], 7)

# for vector in vectors:
#     print(hex(vector))

for i in range(16):
    if(i == 0):
        vectors = F(originalA, originalB, originalC, originalD, Ms[i], Ks[i], 22 - 5*(3 - (i % 4)))
    else:
        # print(hex(vectors[0]), hex(vectors[1]), hex(vectors[2]), hex(vectors[3]))
        # print(hex(vectors[3]), hex(vectors[0]), hex(vectors[1]), hex(vectors[2]))
        # print(str(i + 1) + ": " + str(22 - 5*(3 - (i % 4))))
        # print()
        vectors = F(vectors[3], vectors[0], vectors[1], vectors[2], Ms[i], Ks[i], 22 - 5*(3 - (i % 4)))

# print()

for vector in vectors:
    print(hex(vector))