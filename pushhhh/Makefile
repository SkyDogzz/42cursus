CC = cc
# CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -I$(INC_DIR) -I$(LIBFT_DIR)/include
LDFLAGS = -L$(LIBFT_DIR) -lft

_END    = $(shell printf "\033[0m")
_BOLD   = $(shell printf "\033[1m")
_CYAN   = $(shell printf "\033[36m")
_BLUE   = $(shell printf "\033[34m")

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_SRC_DIR = ../Libft2
LIBFT_DIR = libft

SRC_FILES = main.c stack.c base.c wrapper.c instruction.c parse.c sort.c push.c
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

NAME = push_swap

all: ascii libft $(NAME)
	@echo "$(_CYAN)[BUILD COMPLET]$(_END) $(NAME) est prêt !"

libft: $(LIBFT_DIR)/libft.a

$(LIBFT_DIR)/libft.a:
	@rm -rf $(LIBFT_DIR)
	@cp -r $(LIBFT_SRC_DIR) $(LIBFT_DIR)
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
	@rm -rf $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(_BLUE)[FCLEAN]$(_END) Suppression de $(NAME) et de la copie de libft."

re: fclean all

ascii:
	@echo $(_CYAN)$(_BOLD)
	@echo "PUSH SWAP"
	@echo $(_END)

MAX=500
run_valgrind:
	@ARG="$$(shuf -i 1-$(MAX) -n $(MAX) | tr '\n' ' ' | sed 's/ $$//')"; \
	valgrind -s --leak-check=full ./$(NAME) $$ARG

run:
	@ARG="$$(shuf -i 1-$(MAX) -n $(MAX) | tr '\n' ' ' | sed 's/ $$//')"; \
	./$(NAME) $$ARG

lint:
	@cppcheck --enable=all --inconclusive --std=c99 $(INC_DIR) $(SRC_DIR)

.PHONY: all clean fclean re ascii
