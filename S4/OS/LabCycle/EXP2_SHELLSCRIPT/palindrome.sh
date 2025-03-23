echo " Palindrome "
echo "enter a number"
read num
no=$num
rev=0
while [ $num -gt 0 ]; do
digit=$(( num % 10 ))
rev=$(( rev * 10 + digit ))
num=$(( num / 10 ))
done
if [ $rev -eq $no ] 
then 
echo "The number is a palindrome"
else
echo "The number is not a palindrome"
fi
