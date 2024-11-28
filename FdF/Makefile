NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99 -I./include -I./libft/include/
AR = ar rcs

SRCS = src/main.c src/dim.c src/display.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

bonus: all

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) ./
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a

$(LIBFT):
	@$(MAKE) all -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

reft:
	rm -rf $(LIBFT_DIR) libft.a
	cp -r ../Libft2 ./libft

re: fclean all

.PHONY: all clean fclean re
