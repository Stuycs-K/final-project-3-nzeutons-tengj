import math

def generate_Ms(str):
    Ms = []
    str_index = 0
    for i in range(16):
        if(i == 14):
            Ms.append(0)
        elif(i == 15):
            Ms.append(8 * len(str))
        else:
            M = 0

            if(str_index < len(str)):
                for j in range(4):
                    if(str_index < len(str)):
                        M = M | (ord(str[str_index]) << (24 - 8*(str_index % 4)))
                        if(str_index + 1 == len(str)):
                            if((str_index + 1) % 4 == 0):
                                Ms.append(M)
                                M = 1 << 31
                            else:
                                M = M | (1 << (23 - 8*(str_index % 4)))

                    str_index += 1

            Ms.append(M)

    return Ms

def generate_Ks():
    Ks = []
    for i in range(64):
        Ks.append(int(abs(math.sin(i + 1))*pow(2,32)))

    return Ks

def rotate(num, shift):
    shift_portion = num >> (32 - shift)
    eraser = 0b11111111111111111111111111111111
    num &= eraser >> shift

    return (num << shift) | shift_portion

def F(A, B, C, D, M, K, S):
    result = (B & C) | ((~B) & D)

    result = (result + A) % pow(2, 32)

    result = (result + M) % pow(2, 32)

    result = (result + K) % pow(2, 32)

    result = rotate(result, S)

    result = (result + B) % pow(2, 32)

    return [result, B, C, D]

def G(A, B, C, D, M, K, S):
    result = (B & D) | (C & (~D))

    result = (result + A) % pow(2, 32)

    result = (result + M) % pow(2, 32)

    result = (result + K) % pow(2, 32)

    result = rotate(result, S)

    result = (result + B) % pow(2, 32)

    return [result, B, C, D]

def H(A, B, C, D, M, K, S):
    result = B ^ C ^ D

    result = (result + A) % pow(2, 32)

    result = (result + M) % pow(2, 32)

    result = (result + K) % pow(2, 32)

    result = rotate(result, S)

    result = (result + B) % pow(2, 32)

    return [result, B, C, D]

def I(A, B, C, D, M, K, S):
    result = C ^ (B | (~D))

    result = (result + A) % pow(2, 32)

    result = (result + M) % pow(2, 32)

    result = (result + K) % pow(2, 32)

    result = rotate(result, S)

    result = (result + B) % pow(2, 32)

    return [result, B, C, D]