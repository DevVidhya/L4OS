echo -e "Year "
read year
for (( i = 0; i<5; i++ ))
do 
	read month
	cal $month $year
done
