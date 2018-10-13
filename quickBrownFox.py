n = int(input())
for i in range(n):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    line = input().lower()
    for let in line:
        if let in alphabet:
            alphabet = alphabet.replace(let, "")
    if alphabet == "":
        print("pangram")
    else:
        print("missing " + alphabet)