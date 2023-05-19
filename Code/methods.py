def generate_Ms(str, Ms):
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
                    M = M | (ord(str[str_index]) << (24 - 8*(str_index % 4)))
                    str_index += 1

                Ms.append(M)
            elif(str_index == len(str) and i < 14):
                Ms.append(1 << 31)
            else:
                Ms.append(M)
            
            
        
