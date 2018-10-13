import sys
import math

def dfs(graph, start):
    visited = set()
    stack = [start]
    while stack:
        vertex = stack.pop()
        visited.add(vertex)
        if (vertex in graph):
            stack.extend(graph[vertex] - visited)
    return visited

if __name__ == '__main__':
    m, n = input().split()
    m = int(m)
    n = int(n)
    dict = dict()
    for i in range(m):
        x, y = input().split()
        if(x in dict):
            dict[x].add(y)
        else:
            dict[x] = set([x, y])

    for i in range(n):
        first, second = input().split()
        if(len(first)!=len(second)):
            print("no")
            continue
        for j in range(len(first)):
            if(not (second[j] in dfs(dict, first[j]))):
                # print(first[j] + " in ", end="")
                # print(dfs(u_dict, second[j]))
                print("no")
                break
            if(j == len(first) - 1):
                print("yes")