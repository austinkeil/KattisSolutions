def shiftRowLeft(row):
    c = row.count(0)
    while 0 in row:
        row.remove(0)
    for i in range(c):
        row.append(0)

def shiftRowRight(row):
    c = row.count(0)
    while 0 in row:
        row.remove(0)
    for i in range(c):
        row.insert(0,0)

def mergeLeft(row):
    freeNdx = 0
    for i in range(1, 4):
        if row[i] == row[i - 1]:
            row[i - 1] = row[i] * 2
            row[i] = 0
            freeNdx = i
            break
    shiftRowLeft(row)
    for i in range(freeNdx + 1, 4):
        if row[i] == row[i - 1]:
            row[i - 1] = row[i] * 2
            row[i] = 0
            break
    shiftRowLeft(row)

def mergeRight(row):
    freeNdx = 3
    for i in range(2, -1, -1):
        if row[i] == row[i + 1]:
            row[i + 1] = row[i] * 2
            row[i] = 0
            freeNdx = i
            break
    shiftRowRight(row)
    for i in range(freeNdx-1, -1,-1):
        if row[i] == row[i + 1]:
            row[i + 1] = row[i] * 2
            row[i] = 0
            break
    shiftRowRight(row)

w, h = 4, 4
matrix = [[0 for x in range(w)] for y in range(h)]

for i in range(4):
    line = list(map(int, input().split()))
    for j in range(4):
        matrix[i][j] = line[j]
direction = int(input())
if direction == 0:
    for i in range(4):
        shiftRowLeft(matrix[i])
        mergeLeft(matrix[i])
elif direction == 1:
    matrix = list(zip(*matrix))
    for i in range(4):
        matrix[i] = list(matrix[i])
    for i in range(4):
        shiftRowLeft(matrix[i])
        mergeLeft(matrix[i])
    matrix = list(zip(*matrix))
elif direction == 2:
    for i in range(4):
        shiftRowRight(matrix[i])
        mergeRight(matrix[i])
else:
    matrix = list(zip(*matrix))
    for i in range(4):
        matrix[i] = list(matrix[i])
    for i in range(4):
        shiftRowRight(matrix[i])
        mergeRight(matrix[i])
    matrix = list(zip(*matrix))

for i in range(4):
    for j in range(3):
        print(matrix[i][j], end=" ")
    print(matrix[i][3])