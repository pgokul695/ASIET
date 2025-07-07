def count(str):
	dict={}
	for st in str:
		if st in dict:
			dict[st] += 1
		else:
			dict[st] = 1
	return dict

fp=input("Enter the File path : 	")
with open(fp,'r') as fptr:
	str= fptr.read()
str = str.split()
dict = count(str)
hind = int(-1)
for word,i in dict.items():
	if (i > hind):
		high = word
		hind= i
print(f"The Most Frequent Word is {high} with occurance {dict[high]}")

