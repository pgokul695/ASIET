echo "Enter a number to check odd or even"
read a
n=$(($a % 2))
if [ $n -eq 0 ] 
then
	echo "The number is Even"
else
	echo "The number is ODD"
fi

	
