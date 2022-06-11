echo "Enter a number"
read n

temp=$n
reverse=0
sum=0

while [ $temp -gt 0 ]
do
    Digit=`expr $temp % 10`
    reverse=`expr $reverse \* 10 + $Digit`
    sum=`expr $sum + $Digit`
    temp=`expr $temp / 10`
done

echo "$n in Reverse is $reverse"
echo "Sum of $n is $sum"