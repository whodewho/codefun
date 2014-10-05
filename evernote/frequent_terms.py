counter = dict()
number = int(raw_input())
for i in range(number):
    tmp = raw_input()
    if tmp not in counter:
        counter[tmp] = 1
    else:
        counter[tmp] = counter[tmp] + 1

k = int(raw_input())
array = [v[0] for v in sorted(counter.iteritems(), key=lambda(k, v):(-v,k))]
for i in range(k):
    print array[i]
