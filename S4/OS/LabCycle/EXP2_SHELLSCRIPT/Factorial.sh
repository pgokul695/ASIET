echo "Enter a number to check factorial for"
read a
num=$a
fact=1
while [ $a -gt 1 ];
do	
	fact=$(( a * fact))
	a=$((a - 1))
done
echo "The factorial of $num is $fact"
	
