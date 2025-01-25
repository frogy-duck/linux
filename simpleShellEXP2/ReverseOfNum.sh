#!/bin/bash

# Prompt the user for input
echo "Enter a number: "
read num

# Store the original number
original_num=$num
reverse=0

# Reverse the number
while [ $num -gt 0 ]
do
    digit=$(( num % 10 ))  # Extract last digit
    reverse=$(( reverse * 10 + digit ))  # Append digit to reverse
    num=$(( num / 10 ))  # Remove last digit
done

# Display the reversed number
echo "The reverse of $original_num is: $reverse"
