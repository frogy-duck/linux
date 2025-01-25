#!/bin/bash

# Define the directory and file names
DIR_NAME="my_directory"
FILE_NAME="my_file.txt"

# Check if the directory exists, if not, create it
if [ ! -d "$DIR_NAME" ]; then
    echo "Directory '$DIR_NAME' does not exist. Creating now..."
    mkdir "$DIR_NAME"
    echo "Directory created successfully!"
else
    echo "Directory '$DIR_NAME' already exists."
fi

# Check if the file exists, if not, create it
if [ ! -f "$DIR_NAME/$FILE_NAME" ]; then
    echo "File '$FILE_NAME' does not exist in '$DIR_NAME'. Creating now..."
    touch "$DIR_NAME/$FILE_NAME"
    echo "File created successfully!"
else
    echo "File '$FILE_NAME' already exists in '$DIR_NAME'."
fi

# Prompt user to enter text to append to the file
echo "Enter some text to store in the file:"
read user_text

# Append user input to the file
echo "$user_text" >> "$DIR_NAME/$FILE_NAME"
echo "Text saved in $DIR_NAME/$FILE_NAME"

# Display file contents
echo "File Contents:"
cat "$DIR_NAME/$FILE_NAME"
