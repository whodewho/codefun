import heapq

num = int(raw_input())
numbers = []
for i in range(num):
    numbers.append(int(raw_input()))

h = []
for i in range(4):
    heapq.heappush(h, numbers[i])
for i in range(4, num):
    heapq.heappushpop(h, numbers[i])

for elem in reversed(sorted(h)):
    print elem
