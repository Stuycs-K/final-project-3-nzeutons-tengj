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

for M in Ms:
    print(hex(M))

Ks = generate_Ks()

for K in Ks:
    print(hex(K))

print()

output = F(originalA, originalB, originalC, originalD, Ms[0], Ks[0], 7)

for vector in output:
    print(hex(vector))

# for i in range(16):
#     A
#     F()