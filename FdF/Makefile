NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99 -I./include -I./libft/include/
LDFLAGS = -L./libft/ -L./.minilibx-linux/ -lft -lmlx_Linux -lXext -lX11 -lm
AR = ar rcs

_END    = $(shell printf "\033[0m")
_BOLD   = $(shell printf "\033[1m")
_CYAN   = $(shell printf "\033[36m")
_BLUE   = $(shell printf "\033[34m")

SRCS = src/main.c src/dim.c src/display.c src/event.c src/utils.c src/parse.c \
	   src/projection.c src/draw.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "$(_CYAN)[BUILD COMPLET]$(_END) $(NAME) est prêt !"

$(NAME): $(OBJS)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LOG_DIR = log

bonus: all

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) 

$(LIBFT):
	@$(MAKE) all -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_CYAN)[COMPILATION]$(_END) Création de l'objet : $(_BOLD)$@$(_END)"

clean:
	@rm -f $(OBJS)
	@echo "$(_BLUE)[CLEAN]$(_END) Suppression des fichiers objets."

fclean: clean
	@rm -rf $(NAME) $(LOG_DIR)
	@echo "$(_BLUE)[FCLEAN]$(_END) Suppression de l'exec $(NAME)."

reft:
	@rm -rf $(LIBFT_DIR)
	@cp -r ../Libft2 ./libft
	@echo "$(_BLUE)[REFT]$(_END) Get clear libft $(NAME)."


re: fclean all

rea: reft fclean all

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
