import sys
from methods import *

fileName = sys.argv[1]

f = open(fileName, "r")
message = f.read()

Ms = generate_Ms(message)

for M in Ms:
    print(hex(M))
