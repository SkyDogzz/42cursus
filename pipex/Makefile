CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -march=native -I$(INC_DIR) -I$(LIBFT_DIR)/include
LDFLAGS = -L$(LIBFT_DIR) -lft

_END    = $(shell printf "\033[0m")
_BOLD   = $(shell printf "\033[1m")
_CYAN   = $(shell printf "\033[36m")
_BLUE   = $(shell printf "\033[34m")

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

SRC_FILES = parse.c path.c pipex.c process.c utils.c
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

NAME = pipex

all: ascii libft $(NAME)
	@echo "$(_CYAN)[BUILD COMPLET]$(_END) $(NAME) est prêt !"

libft: $(LIBFT_DIR)/libft.a

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(_CYAN)[LINKING]$(_END) $(NAME) est créé !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_CYAN)[COMPILATION]$(_END) Création de l'objet : $@"

clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi
	@echo "$(_BLUE)[CLEAN]$(_END) Suppression des fichiers objets."

fclean: clean
	@rm -rf $(LIBFT_DIR)/libft.a
	@rm -f $(NAME)
	@echo "$(_BLUE)[FCLEAN]$(_END) Suppression de $(NAME) et de la copie de libft."

re: fclean all

ascii:
	@echo $(_CYAN)$(_BOLD)
	@echo "PUSH SWAP"
	@echo $(_END)

.PHONY: all clean fclean re ascii
