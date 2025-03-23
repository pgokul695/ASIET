echo "Calculator"
echo "Enter two numbers"
read a
read b
echo "Select operation"
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
read c
case $c in
1) echo "$a + $b = $((a+b))";;
2) echo "$a - $b = $((a-b))";;
3) echo "$a * $b = $((a*b))";;
4) echo "$a / $b = $((a/b))";;
esac
