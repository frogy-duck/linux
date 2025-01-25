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

# Check if reversed number is equal to the original number
if [ $original_num -eq $reverse ]
then
    echo "$original_num is a palindrome number."
else
    echo "$original_num is not a palindrome number."
fi
