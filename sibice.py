import math
nwh = list(map(int, input().split()))

for i in range(nwh[0]):
    temp = int(input())
    if(temp <= math.sqrt(nwh[1]**2 + nwh[2]**2)):
        print("DA")
    else:
        print("NE")