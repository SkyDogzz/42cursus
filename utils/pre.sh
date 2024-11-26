#!/bin/bash

if [ -f Makefile ]; then
    echo "Running make fclean..."
    make fclean || { echo "make fclean failed, aborting push."; exit 1; }
else
    echo "No Makefile found, skipping make fclean."
fi

echo "Running norminette..."
output=$(norminette 2>&1)
echo "$output" | grep -v "OK"

echo "Checking for files not ending with .c, .h, or Makefile..."
find . -type f ! \( -name "*.c" -o -name "*.h" -o -iname "makefile" \) | while read -r file; do
    echo "Unauthorized file: $file"
done

