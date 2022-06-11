echo "Enter size of an array"
read n

for((i=0;i<n;i++))
do
    echo "Input $((i+1)) number"
    read nos[$i]
done

echo "Array Elements"
for((i=0;i<n;i++))
do
    echo ${nos[$i]}
done

small=${nos[0]}
largest=${nos[0]}
for((i=0;i<n;i++))
do

    if [ ${nos[$i]} -lt $small ]; then
    small=${nos[$i]}

elif [ ${nos[$i]} -gt $largest ]; then
    largest=${nos[$i]}
fi
done

echo "smallest number in an array is $small"
echo "largest number in an array is $largest"