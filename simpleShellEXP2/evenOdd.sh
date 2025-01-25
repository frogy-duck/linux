#!/bin/bash

# Prompt the user for input
echo "Enter a number: "
read num

# Check if the number is even or odd
if (( num % 2 == 0 ))
then
    echo "$num is an even number."
else
    echo "$num is an odd number."
fi
