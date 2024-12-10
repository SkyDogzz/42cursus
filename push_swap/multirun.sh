#!/bin/bash

RUNS=100

min=999999999
max=0
total=0

for i in $(seq 1 $RUNS); do
    echo "Run $i / $RUNS"
    result=$(./push_swap "$(shuf -i 1-500 -n 500)" | grep -o '^[^ ]*')
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

