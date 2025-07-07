a= set(map(int,input("Enter a list of integers [Space Seperated]").split()))
b= set(map(int,input("Enter a second list of integers [Space Seperated]").split()))
print(f"Set A : {a}\nSet B:{b}");
print(f"A Union B : {a|b}\nA Intersection B: {a&b}");

