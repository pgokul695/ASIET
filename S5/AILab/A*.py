import heapq

def A(n, edges, hue, start, goal):
    # Dynamically determine the range of node indices based on input
    graph = {}
    for u, v, _ in edges:
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
    for u, v, h in edges:
        graph[u].append((v, h))  # Add edge with cost to graph

    # Initialize visited nodes set and priority queue (min-heap)
    visited = set()
    pq = []
    heapq.heappush(pq, (hue[start], 0, start, [start]))  # Push (f, g, node, path)
    
    while pq:
        # f, g, node, path
        f, g, node, path = heapq.heappop(pq)
        
        if node in visited:
            continue
        
        visited.add(node)
        
        if node == goal:
            print(f"Path found, The final Cost: {g}") 
            print(" ".join(map(str, path)))
            return
        
        for n, hc in graph[node]:
            if n not in visited:
                gn = g + hc  # g(n) = g(parent) + cost
                hn = hue[n]  # Heuristic for the neighbor
                fn = gn + hn  # f(n) = g(n) + h(n)
                heapq.heappush(pq, (fn, gn, n, path + [n]))  # Push new node to pq with updated path
    
    print("No path exists")

# Input handling
n = int(input('Enter the number of nodes: '))
hue = {}
print("Enter the name and Heuristics of each node (Space Separated):")
for _ in range(n):
    node, h = map(int, input().split())
    hue[node] = h  # Store heuristic in a dictionary

e = int(input('Enter the number of edges: '))
edges = []
print("Enter From To Cost for each edge (Space Separated): ")
for _ in range(e):
    u, v, c = map(int, input().split())
    edges.append((u, v, c))  # Store edges as (from, to, cost)

start = int(input("Enter the starting node: "))
goal = int(input("Enter the goal node: "))

A(n, edges, hue, start, goal)

