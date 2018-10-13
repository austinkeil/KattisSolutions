import math

line = input()
while(line):
    totalTime = 0
    params = list(map(float, line.split()))

    #give the params names as not to get lost in indeces
    n = params[0]
    v = params[1]
    x = params[2]
    f = params[3]
    t = params[4]

    loads = v/x

    print()
    print("total volume: %f" % v)
    print("bucket size: %f" % x)
    print("fill rate: %f" % f)
    print("bucket loads: %f" % loads)

    timeToExch = x/f
    exchangeTime = timeToExch*(n+1)*math.ceil(loads)
    turnTime = math.ceil(loads)*t*2
    refill = math.fabs((math.floor(v/x) - v/x))
    refillTime = refill/f
    print("time to fill: %f" % timeToExch)
    print("total trip time (no turns): %f" % (exchangeTime))
    print("time turning: %f" % turnTime)
    print("total trip time (with turns): %f" % (exchangeTime + turnTime))
    print()
    print("DONE FILLING BUCKET!")
    print()
    print("amount to refill: %f" % refill)
    print("refill time: %f" % refillTime)

    line = input()