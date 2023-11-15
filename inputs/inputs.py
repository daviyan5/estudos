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

def kd_tree():
    # Número de dimensões
    k = 3

    # Número de pontos
    n = 100

    # Pontos
    points = np.random.uniform(-n // 2, n // 2, (n, k))

    # Pontos de consulta
    q = random.randint(n // 2, n * 2)
    queries = np.random.uniform(-n // 2, n // 2, (q, k))

    print("{} {}".format(k, n), file=open(f"./inputs/kd-tree.in", "w"))
    for i in range(n):
        for j in range(k):
            print("{} ".format(points[i][j]), end="", file=open(f"./inputs/kd-tree.in", "a"))
        print("", file=open(f"./inputs/kd-tree.in", "a"))
    print("{}".format(q), file=open(f"./inputs/kd-tree.in", "a"))
    for i in range(q):
        for j in range(k):
            print("{} ".format(queries[i][j]), end="", file=open(f"./inputs/kd-tree.in", "a"))
        print("", file=open(f"./inputs/kd-tree.in", "a"))
    if(n > 1000 or q > 1000):
        return
    # Represent the points in matplotlib
    import matplotlib.pyplot as plt
    fig = plt.figure()
    if k == 2:
        ax = fig.add_subplot()
        ax.scatter(points[:,0], points[:,1], c='r', marker='o')
        for i in range(n):
            ax.annotate(i, (points[i,0], points[i,1]), color='red')
        ax.scatter(queries[:,0], queries[:,1], c='b', marker='^')
        for i in range(q):
            ax.annotate(i, (queries[i,0], queries[i,1]), color='blue')
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.legend(['Points', 'Queries'])
    else:
        ax = fig.add_subplot(projection='3d')
        ax.scatter(points[:,0], points[:,1], points[:,2], c='r', marker='o')
        ax.scatter(queries[:,0], queries[:,1], queries[:,2], c='b', marker='^')
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        ax.legend(['Points', 'Queries'])
    #plt.show()
    
    plt.savefig(f"./inputs/kd-tree.png")
    
def main():
    if len(sys.argv) != 2:
        print("Usage: ./inputs.py FILENAME")
        sys.exit(1)
    match(sys.argv[1]):
        case "bfs":
            graph()
        case "busca-binaria":
            ordered_array()
        case "kd-tree":
            kd_tree()
if __name__ == "__main__":
    main()
