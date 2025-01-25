#!/bin/bash

# Prompt the user for input
echo "Enter a number: "
read num

# Initialize factorial to 1
factorial=1

# Check if the number is negative
if [ $num -lt 0 ]
then
    echo "Factorial of a negative number is not defined."
    exit 1
fi

# Loop to calculate factorial
for (( i=1; i<=num; i++ ))
do
    factorial=$(( factorial * i ))
done

# Display the result
echo "Factorial of $num is: $factorial"
