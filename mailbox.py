
#INCOMPLETE
n = int(input())
for i in range(n):
    k, m = map(int, input().split())
    cur = 0
    sum = 0
    other = 1
    i=1
    upper = m
    while i < k:
        upper = cur
        cur = (cur + m) // 2
        print(cur)
        sum += cur
        if other%2==0:
            i += 1
        other += 1
    sum += (upper-1)*(upper)/2 - cur*(cur+1)/2
    print(sum)