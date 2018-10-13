t = int(input())
for j in range(t):
    sounds = input().split()
    temp = input().split()
    while(temp[len(temp)-1] != "say?"):
        while(temp[len(temp)-1] in sounds):
            sounds.remove(temp[len(temp)-1].strip())
        temp = input().split()
    for i in range(len(sounds)-1):
        print(sounds[i], end=" ")
    print(sounds[-1])