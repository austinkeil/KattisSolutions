x = int(input())
n = int(input())
used = 0
available = x*(n+1)
for i in range(n):
    used += int(input())
print(available-used)