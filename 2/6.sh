#!/bin/bash
echo "Enter values of n"
read n
echo "Enter values of r"
read r
N=1
R=1
NR=1
	for (( i = 1; i <= $n; i++ ))
	do
		N=$(( $N * $i ))
	done
	for (( i = 1; i <= $r; i++ ))
	do
		R=$(( $R * $i ))
	done
nr=$(( $n - $r ))
	for (( i = 1; i <= $nr; i++ ))
	do
		NR=$(( $NR * $i ))
	done
cr=$(( $R * $NR ))
ncr=$(( $N / $cr ))
echo "Combination: $ncr"
