NAME = fdf

CC = cc
# CFLAGS = -Wall -Wextra -Werror -std=c99 -I./include -I./libft/include/
LDFLAGS = -L./libft/ -L./.minilibx-linux/ -lft -lmlx_Linux -lXext -lX11 -lm
AR = ar rcs

SRCS = src/main.c src/dim.c src/display.c src/event.c src/utils.c src/parse.c \
	   src/projection.c src/draw.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LOG_DIR = log

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
	rm -f $(NAME) $(TEST_DIR)

reft:
	rm -rf $(LIBFT_DIR)
	cp -r ../Libft2 ./libft


re: fclean all

lint:
	@mkdir -p $(LOG_DIR)
	@cppcheck --enable=all --inconclusive --std=c99 src \
	--suppress=unusedFunction --suppress=unusedVariable \
	--suppress=variableScope --suppress=missingIncludeSystem \
	--check-level=exhaustive --suppress=unmatchedSuppression \
	--suppress=shiftTooManyBitsSigned \
	--suppress=checkersReport 2> $(LOG_DIR)/lint_errors.log
	@echo "$(_CYAN)Résultats de cppcheck enregistrés dans lint_errors.log$(_END)"

.PHONY: all clean fclean re
