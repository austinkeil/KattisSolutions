l = list()
count = 0
for i in range(10):
    temp = int(input())
    if temp % 42 not in l:
        l.append(temp%42)
        count += 1
print(count)