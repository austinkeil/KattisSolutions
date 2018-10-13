n = input()
sizes = list(map(int, input().split()))

A2_LEN = 2 ** (-3.0 / 4.0)
A2_WID = 2 ** (-5.0 / 4.0)
A2_AREA = A2_LEN * A2_WID
A1_LEN = 2 * A2_WID
A1_AREA = 2 * A2_AREA

areaRemaining = A1_AREA
aSize = 2
length = 0

widths = [A2_WID]
lengths = [A2_LEN]

for aSize in range(len(sizes)):
    widths.add(lengths[aSize] / 2)
    length += lengths[aSize]
    areaRemaining -= A2_AREA
print(length)
