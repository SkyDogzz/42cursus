NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = src/ft_printf.c src/ft_char.c src/ft_option.c src/ft_parse.c \
	   src/ft_str.c src/ft_uint.c src/ft_p.c src/ft_nbr.c src/ft_store.c \
	   src/ft_u.c arc/ft_util.c
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
