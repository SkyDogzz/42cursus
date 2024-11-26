#!/bin/bash

if [ "$#" -eq 1 ]; then
	cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c .main.c -D BUFFER_SIZE=$1
else
    cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c .main.c
fi
