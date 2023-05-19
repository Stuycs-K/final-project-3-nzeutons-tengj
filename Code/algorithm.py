from methods import *

message = "They are deterministic"
Ms = []

generate_Ms(message, Ms)

for M in Ms:
    print(hex(M))
