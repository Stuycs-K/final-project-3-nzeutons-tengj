from methods import *

message = "They are deterministic"
Ms = generate_Ms(message)

for M in Ms:
    print(hex(M))
