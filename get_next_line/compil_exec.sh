#!/bin/bash

if [ "$#" -lt 1 ]; then
	echo "Usage: $0 <input_file> [BUFFER_SIZE]" 
	exit 1
fi

if [ "$#" -eq 2 ]; then
	cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c .main.c -D BUFFER_SIZE=$2
else
    cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c .main.c
fi
	./a.out "$1"
