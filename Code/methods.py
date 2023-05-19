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
                    if(str_index < len(str)):
                        M = M | (ord(str[str_index]) << (24 - 8*(str_index % 4)))
                        str_index += 1
                    elif(str_index == len(str)):
                        M = M | (1 << (24 - 8*(str_index  % 4)))
                        str_index += 1
                        print(bin((1 << (24 - 8*(str_index  % 4)))))
            elif(str_index == len(str)):
                M = 1 << 31

            Ms.append(M)
            
            
        
