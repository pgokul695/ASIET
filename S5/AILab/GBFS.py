import heapq
def gbfs(n,edges,start,goal):
	graph = {i:[] for i in range(n)}
	for u,v,h in edges: graph[u].append((v,h))
	
	visited = set()
	pq = []
	traversal = []
	heapq.heappush(pq, (0,start,[start]))
	while pq:
		h,node,path = heapq.heappop(pq)
		if node in visited:
			continue
		visited.add(node)
		traversal.append(node)
		if node == goal:
			print(" ".join(map(str,traversal))+" ")
			return
		for n,hc in graph[node]:
			if n not in visited:
				heapq.heappush(pq, (hc,n,path+[n]))
	print("No path exists");

n = int(input('Enter the number of nodes: '))
e = int (input('Enter the number of edges: '))
edges = []
print("Enter From To Cost for each edge (Space Seperated) ");
for _ in range(e):
	u,v,c = map(int,input().split())
	edges.append((u,v,c))
start = int(input("Enter the starting node: "));
goal = int(input("Enter the goal node: "));
gbfs(n,edges,start,goal)
