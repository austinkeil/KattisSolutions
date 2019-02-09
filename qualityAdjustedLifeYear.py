n = int(input())
tot = 0
for i in range(n):
    [x, y] = list(map(float, input().split()))
    tot += x * y
print(tot)