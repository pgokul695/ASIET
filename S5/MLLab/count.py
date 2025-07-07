a= input("Enter a string").split();
dict={}
for st in a:
	if st in dict:
		dict[st] += 1
	else:
		dict[st] = 1
print(f"The occurance of each word\n{dict}");
