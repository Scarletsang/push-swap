#!/bin/bash

# Usage: ./generate_numbers.sh n
# where n is the number of random non-repeating numbers you want to generate

n=$1
limit=$(($1 * 10))
numbers=()
for ((i=1; i<=$n; i++)); do
    number=$((1 + RANDOM % limit))
    while [[ "${numbers[@]}" =~ "${number}" ]]; do
        number=$((1 + RANDOM % limit))
    done
    numbers+=("$number")
done

echo "${numbers[@]}"