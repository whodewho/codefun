length = int(raw_input())
buf = [""] * length 
begin = 0
size = 0

while True:
    print buf
    cmd = raw_input().split()
    if cmd[0] == 'A':
        for i in range(int(cmd[1])):
            new_string = raw_input()
            if size == 0:
                buf[begin] = new_string
                size = size + 1
            elif size == length:
                buf[begin] = new_string
                begin = (begin + 1) % length
            else:
                buf[(begin + size) % length] = new_string
                size = size + 1
    elif cmd[0] == 'R':
        r_length = int(cmd[1])
        if r_length >= size:
             buf = [""] * length
             begin = 0
             size = 0
        else:
            for i in range(r_length):
                buf[(begin+i) % length] = ""
            begin = (begin + r_length) % length
            size = size - r_length
    elif cmd[0] == 'L':
        for i in range(size):
            print buf[(begin + i)%length]
    elif cmd[0] =='Q':
        exit()
            
        
