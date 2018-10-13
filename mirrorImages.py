t = int(input())
for i in range(1, t+1):
    r, c = list(map(int, input().split()))
    print("Test " + str(i))
    matrix = list()
    for j in range(r):
        matrix.append(input()[::-1].strip())
    for m_i in range(len(matrix)-1, -1, -1):
        print(matrix[m_i])
