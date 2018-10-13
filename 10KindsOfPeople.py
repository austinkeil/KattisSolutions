def dfs(r1, c1, r2, c2, graph):
    start = graph[r1][c1] #1 or 0 based on start
    stack = [(r1, c1)]
    visited = set()
    while stack:
        vertex = stack.pop()
        row = vertex[0]
        col = vertex[1]
        if row == r2 and col == c2:
            return start
        visited.add(vertex)
        if graph[row-1][col] == start and (row-1, col) not in visited:
            stack.append((row-1, col))
        if graph[row+1][col] == start and (row+1, col) not in visited:
            stack.append((row + 1, col))
        if graph[row][col+1] == start and (row, col+1) not in visited:
            stack.append((row, col + 1))
        if graph[row][col-1] == start and (row, col-1) not in visited:
            stack.append((row, col - 1))
    return -1


r, c = list(map(int, input().split()))
graph = ["-"*(c+2)]
for i in range(0,r):
    graph.append("-" + input().strip() + "-")
graph.append("-"*(c+2))

n = int(input())
for i in range(n):
    r1, c1, r2, c2 = list(map(int, input().split()))
    result = int(dfs(r1, c1, r2, c2, graph))
    if result == 1:
        print("decimal")
    elif result == 0:
        print("binary")
    else:
        print("neither")