def read(name):
	mat=list()
	row = int(input(f"Enter the number of rows of {name} matrix : "))
	col = int(input(f"Enter the number of cols of {name} matrix : "))
	for i in range(row):
			ls = list(map(int,input(f"Enter the {i}th Row [Space Seperated] : ").split()))
			mat.append(ls)
	return mat,row,col

def mul(A,B,row,col,col2):
	Result=[[0 for i in range(col2)] for i in range(row)]
	for i in range(row):
		for j in range(col2):
			for k in range(col):
				Result[i][j]+= A[i][k] * B[k][j]
	return Result

A,ra,ca = read("A")
B,rb,cb = read("B")

if(ca != rb):
	raise ValueError("Two matrices cannot be added")

r=mul(A,B,ra,ca,cb)
print("Resultant matrix R =");
for i in range(ra):
	for j in range(cb):
		print(f"{r[i][j]}", end=" ")
	print()



