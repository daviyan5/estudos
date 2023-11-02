import random
import sys
import numpy as np

def graph():
    n   = random.randint(10, 1000)
    m   = 0
    lim = 7
    nodes = list(range(n))
    edges = []

    for i in range(n):
        cur = 0
        for j in range(i+1, n):
            if random.choice([True, False]):
                m += 1
                edges.append((i, j))
                cur += 1
            if cur == lim:
                break
    print("{}".format(n), file=open(f"./inputs/bfs.in", "w"))
    print("{}".format(m), file=open(f"./inputs/bfs.in", "a"))
    for edge in edges:
        print("{} {}".format(edge[0], edge[1]), file=open(f"./inputs/bfs.in", "a"))
    return nodes, edges

def ordered_array():
    n = random.randint(10, 1000)
    v = np.random.randint(0, n // 10, n)
    v.sort()
    print("{}".format(n), file=open(f"./inputs/busca-binaria.in", "w"))
    for i in range(n):
        print("{}".format(v[i]), file=open(f"./inputs/busca-binaria.in", "a"))
    idx = random.choice(range(n))
    print("{}".format(v[idx]), file=open(f"./inputs/busca-binaria.in", "a"))
    
def main():
    if len(sys.argv) != 2:
        print("Usage: ./inputs.py FILENAME")
        sys.exit(1)
    match(sys.argv[1]):
        case "bfs":
            graph()
        case "busca-binaria":
            ordered_array()
if __name__ == "__main__":
    main()
