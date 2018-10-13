import sys
import math

if __name__ == '__main__':
    n = int(input())
    teaPrices = input().split()
    m = int(input())
    toppingPrices = input().split()

    minimum = 200000
    for i in range(n):
        tops = input().split()
        tops.pop(0)
        for top in tops:
            if(int(teaPrices[i]) + int(toppingPrices[int(top)-1]) < minimum):
                minimum = int(teaPrices[i]) + int(toppingPrices[int(top)-1])
    money = int(input())
    studs = 0
    money = money - minimum
    if(money>=0):
        studs = int(money/minimum)
    print(int(money/minimum))