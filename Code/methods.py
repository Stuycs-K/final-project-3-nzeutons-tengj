def generate_Ms(str, arr):
    str_index = 0
    for i in range(16):
        M = 0
        order = str_index % 4

        M = M | (ord(str[str_index]) << (str_index % 4))
