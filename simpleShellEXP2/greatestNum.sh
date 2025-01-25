#!/bin/bash

# Prompt the user for input
echo "Enter three numbers: "
read num1 num2 num3

# Determine the greatest number
if [[ $num1 -ge $num2 && $num1 -ge $num3 ]]
then
    echo "The greatest number is: $num1"
elif [[ $num2 -ge $num1 && $num2 -ge $num3 ]]
then
    echo "The greatest number is: $num2"
else
    echo "The greatest number is: $num3"
fi
