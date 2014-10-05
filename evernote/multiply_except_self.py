n = int(raw_input())
array = []
zero_index = -1
mul = 1
for i in range(n):
    t = int(raw_input())
    array.append(t)
    if mul !=0 and t ==0:
        zero_index = i
    mul = mul * t
    
if mul == 0:
    mul = 1
    for i in range(n):
        if i == zero_index: continue
        mul = array[i] * mul
    for i in range(n):
        if i == zero_index: print mul
        else: print 0
else:
    for i in range(n):
        print mul/array[i]
