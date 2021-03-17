echo "Enter number of students"
read n
declare -A arr
for(( i = 0; i < n; i++ ))
do
	for(( j = 0; j < 2; j++ ))
	do
		read arr[$i,$j]
	done
done

for(( i = 0; i < n; i++ ))
do
	for(( j = 0; j < 2; j++ ))
	do
		echo ${arr[$i,$j]}
	done
done
