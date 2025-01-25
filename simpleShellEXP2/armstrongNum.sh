#!/bin/bash

# Prompt the user for input
echo "Enter a number: "
read num

# Store the original number
original_num=$num
sum=0

# Calculate the number of digits
num_digits=${#num}

# Loop to calculate the sum of digits raised to the power of num_digits
while [ $num -gt 0 ]
do
    digit=$(( num % 10 ))  # Extract last digit
    sum=$(( sum + digit**num_digits ))  # Add digit^num_digits to sum
    num=$(( num / 10 ))  # Remove last digit
done

# Check if sum is equal to the original number
if [ $sum -eq $original_num ]
then
    echo "$original_num is an Armstrong number."
else
    echo "$original_num is not an Armstrong number."
fi
