#!/bin/bash
	echo "1.Add"
	echo "2.Subtract"
	echo "3.Multiply"
	echo "4.Divide";
	echo "5.Length";
	echo "6.Compare";
	echo "7.Concatenate";
	echo "Choice";
	read n;

	echo "Input";

	case $n in
		1) read a b
			echo "Sum: $((a+b))"   
		;;
		2) read a b
			echo "Difference: $((a-b))" 
		;;
		3) read a b
			echo "Product: $((a*b))" 
		;;
		4) read a b
			echo "Division: $((a/b))" 
		;;
		5) read a
			l=${#a}
			printf "Length: %d" $l
		;;
		6) read a b
			if [[ "$a" == *$b* ]]; then
				echo "Same"
			else
				echo "Different"
			fi
		;;
		7) read a b
			echo "Concatenated string: $a$b"
		;;
		*) echo "Enter correct choice";
	esac
