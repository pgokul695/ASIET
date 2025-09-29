import itertools
def TSP(cities, distmatrix):
	start = int(input("Enter the starting city: "))
	if(start >= len(cities)):
		print("Error: The city specified Doesnt Exists \nExiting......")
		exit(0)
	others = cities.copy()
	others.remove(start)
	mincost = 10e9
	bestpath=[]
	
	for order in itertools.permutations(others):
		cp = [start]+list(order)+[start]
		cc = 0
		
		for i in range(len(cp) - 2):
			cc += distmatrix[cp[i]][cp[i+1]]
		if cc < mincost:
			mincost = cc
			bestpath = cp
	return bestpath,mincost

num = int(input("Enter the number of cities: "))
cities = list(range(num))
distmatrix = list()
for _ in range(num):
	print(f"Enter the travel cost from city {_} to all other cities in order space seperated: ")
	l = list(map(int,input().split()))
	distmatrix.append(l)

print(f"The Cities list : {cities}")
print(f"The distance matrix : {distmatrix}")

bestpath,mincost = TSP(cities,distmatrix)
print(f"The best path to explore is {bestpath}")
print(f"The Cost : {mincost} Taken to explore")

