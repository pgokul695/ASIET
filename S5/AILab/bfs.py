from collections import deque

def bfs(node, graph, goal):
	visited = set()
	que = deque()
	que.append(node)
	while(que):
		node = que.popleft()
		if(node  in visited):
			continue
		visited.add(node)
		print (f"{node} : visited")
		if(node == goal):
			print("Goal Reached")
			return True
		for n in graph[node]:
			if n not in visited:
				que.append(n)
	print("Goal Cannot be reached");
	return False
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
start = input("Enter the starting node : ")
goal = input("Enter the Goal node : ")
bfs(start,graph,goal)

