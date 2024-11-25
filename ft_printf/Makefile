NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99 -fPIE -I/include
AR = ar rcs

SRCS = src/ft_printf.c src/ft_option.c src/ft_parse.c src/ft_store.c \
	   src/ft_printf_utils.c src/ft_util.c src/ft_c.c src/ft_s.c src/ft_p.c \
	   src/ft_d.c src/ft_u.c src/ft_xX.c src/ft_color.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

bonus: all

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re
