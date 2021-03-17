#!/bin/bash
	echo "Angle: "
	read n
    n=$(( $n * 22 / 180 ))
	n=$(( $n / 7 ))
    t=n
    sum=n
	for (( i = 1; i <= 4; i++ ))
	do
		t=$((($t * ( -1 ) * $n * $n ) / ( 2 * $i * ( 2 * $i + 1 ))));
		sum=$(( $sum + $t ))
	done
    echo $sum


