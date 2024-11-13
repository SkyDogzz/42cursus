NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror libft.a
AR = ar rcs

SRCS = src/ft_printf.c src/ft_option.c src/ft_ptr.c src/ft_int.c \
	   src/ft_char.c src/ft_parse.c src/ft_str.c src/ft_hex.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
