#!/bin/bash

echo "===== Using While Loop (Count from 1 to 5) ====="
count=1
while [ $count -le 5 ]; do
    echo "Count: $count"
    ((count++))
done

echo "===== Using For Loop (Iterate over a list of items) ====="
for item in Apple Banana Cherry Mango; do
    echo "Fruit: $item"
done

echo "===== Using Until Loop (Count down from 5 to 1) ====="
count=5
until [ $count -lt 1 ]; do
    echo "Countdown: $count"
    ((count--))
done
