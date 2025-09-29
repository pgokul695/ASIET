def dlsh(node,goal,graph,limit):
	visited = set()
	
	def dls(node,goal,graph,limit):
		if (limit <= 0):
			return False
		visited.add(node)
		print(f"{node} - Visited");
		if( node == goal):
			print(" Goal reached");
			return True
		for n in graph[node]:
			if n not in visited:
				if (dls(n,goal,graph,limit-1)):
					return True
	if(dls(node,goal,graph,limit)):
		return True
	print("Goal Cannot be reached within the given limit");
	
	
#driver
graph = {}
print("Enter all the nodes (Space seperated)")
nodes = input().split()
for n in nodes:
	print(f"Enter all the neighbours of {n}(Space Seperated)")
	graph[n] = input().split()
print("Graph is")
print(graph)
start = input("Enter the starting node: ")
goal = input("Enter the Goal node: ")
limit = int(input("Enter the depth limit: "))
dlsh(start,goal,graph,limit)

	
