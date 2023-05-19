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
                        if(str_index + 1 == len(str)):
                            if((str_index + 1) % 4 == 0):
                                Ms.append(M)
                                M = 1 << 31
                            else:
                                M = M | (1 << (23 - 8*(str_index % 4)))

                    str_index += 1

            Ms.append(M)
            
            
        
