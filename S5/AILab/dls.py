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
graph = { 'A' :['B','C'],
	'B' :['D','E'],
	'C': ['F'],
	'D' : ['G'],
	'G' : [],
	'E' : [],
	'F' : []
}
print("Graph is")
print(graph)
start = input("Enter the starting node: ")
goal = input("Enter the Goal node: ")
limit = int(input("Enter the depth limit: "))
dlsh(start,goal,graph,limit)

	
