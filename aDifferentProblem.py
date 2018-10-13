while True:
    try:
        s = input()
        a, b = list(map(int, s.split()))
        print(abs(a - b))
    except EOFError:
        break
