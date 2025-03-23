echo " sum of digits of a number"
echo "enter a number"
read num
no=$num
sum=0
while [ $num -gt 0 ]; do
digit=$(( num % 10 ))
sum=$(( sum + digit ))
num=$(( num / 10 ))
done
echo "The sum of digits of $no is $sum"


