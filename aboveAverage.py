c = int(input())
for i in range(c):
    grades = list(map(int, input().split()))
    total = 0
    for j in range(1, len(grades)):
        total += grades[j]
    average = total/grades[0]
    aboveavg = 0;
    for j in range(1, len(grades)):
        if(grades[j] > average):
            aboveavg += 1
    print("%0.3f%%" % (aboveavg/grades[0]*100))

