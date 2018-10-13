r, c = list(map(int, input().split()))
matrix = [['0' for x in range(c)] for y in range(r)]

for i in range(r):
    matrix[i] = input()

matrix = list(zip(*matrix))

for i in range(c):
    matrix[i] = list(matrix[i])

    if("#" in matrix[i]):
        next_ob = matrix[i].index("#")
        matrix[i][:next_ob] = sorted(matrix[i][:next_ob])
        if next_ob == c - 1:
            continue
        last = next_ob
        while('#' in matrix[i][last+1:]):
            next_ob = matrix[i].index("#", last+1)
            matrix[i][last+1: next_ob] = sorted(matrix[i][last+1, next_ob])
            last = next_ob
            if next_ob == c-1:
                break;
    else:
        matrix[i] = sorted(matrix[i])

matrix = list(zip(*matrix))
for i in range(r):
    temp = ''.join(matrix[i])
    print(temp)
