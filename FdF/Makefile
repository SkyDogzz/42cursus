NAME = fdf

CC = cc
# CFLAGS = -Wall -Wextra -Werror -std=c99 -I./include -I./libft/include/
LDFLAGS = -L./libft/ -L./.minilibx-linux/ -lft -lmlx_Linux -lXext -lX11
AR = ar rcs

SRCS = src/main.c src/dim.c src/display.c src/event.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

bonus: all

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) 

$(LIBFT):
	@$(MAKE) all -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

reft:
	rm -rf $(LIBFT_DIR)
	cp -r ../Libft2 ./libft


re: fclean all

.PHONY: all clean fclean re
