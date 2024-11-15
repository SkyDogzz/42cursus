NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = src/ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	@make -C libft 
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
