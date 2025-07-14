import numpy as np
di=[ (1 , 6012),
	(2 , 7079),
	(3 , 6886),
	(4 , 7230),
	(5 , 4598),
	(6 , 5564),
	(7 , 6971),
	(8 , 7763),
	(9 , 8032),
	(10 , 9569)]
dt=[('day',int),('Walked_steps',int)]	

steps=np.array(di,dtype=dt)

#adding the steps as compensation
#for i in range(10):
#	steps[i][1] += 2000;
steps['Walked_steps']+=2000;
#printing steps >  9000 and days

'''
print("Steps Walked more than 9000\nday : steps")
for i in range(10):
	if(steps[i][1] > 9000):
		print(steps[i][0] ,":", steps[i][1])
'''

print("Steps Walked more than 9000")
mask = steps['Walked_steps'] > 9000
filtered_steps = steps[mask]
print(filtered_steps)

#steps_sorted=np.sort(steps["Walked_steps"])

steps_sorted= steps[steps["Walked_steps"].argsort()]

print("Sorted Array")

print("Day    :     Steps")
for i in range(10):	
	print(f"{steps_sorted[i][0]}    :    {steps_sorted[i][1]}")
	
#print(steps_sorted)
	
