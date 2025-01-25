#!/bin/bash

# Prompt the user for input
echo "Enter a number: "
read num

sum=0
temp=$num

# Loop to calculate sum of digits
while [ $temp -gt 0 ]
do
    digit=$(( temp % 10 ))  # Extract last digit
    sum=$(( sum + digit ))  # Add to sum
    temp=$(( temp / 10 ))   # Remove last digit
done

# Display the result
echo "The sum of digits of $num is: $sum"
