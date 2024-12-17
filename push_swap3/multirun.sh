#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
	echo "Usage $0 \$max"
	exit
fi

RUNS=100

min=999999999
max=0
total=0

for i in $(seq 1 $RUNS); do
    echo "Run $i / $RUNS"
    # result=$(./push_swap "$(shuf -i 1-500 -n 500)" | grep -o '^[^ ]*')
	result=$(./push_swap "$(shuf -i 1-$1 -n $1 | tr '\n' ' ' | sed 's/ $//')" | wc -l)
    echo "Instructions: $result"
    if [ "$result" -lt "$min" ]; then
        min=$result
    fi
    if [ "$result" -gt "$max" ]; then
        max=$result
    fi
    total=$((total + result))
done
average=$((total / RUNS))
echo "==========================="
echo "Résultats après $RUNS exécutions :"
echo "Nombre minimum d'instructions : $min"
echo "Nombre maximum d'instructions : $max"
echo "Nombre moyen d'instructions : $average"

