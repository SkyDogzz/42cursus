CC = cc
# CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -funroll-loops -flto -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

_END    = $(shell printf "\033[0m")
_BOLD   = $(shell printf "\033[1m")
_CYAN   = $(shell printf "\033[36m")
_BLUE   = $(shell printf "\033[34m")

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_SRC_DIR = ../Libft2
LIBFT_DIR = libft
MLX_DIR = ./.minilibx

SRC_FILES = main.c setup.c draw/draw_helpers.c draw/draw_line.c draw/draw_map.c event/event_exit.c event/event_handlers.c event/event_key.c map/map_parse.c map/map_refill.c map/map_utils.c utils/color_utils.c utils/helper_utils.c utils/key_utils.c utils/math_utils.c utils/rotation_ops.c utils/rotation_utils.c  zoom_utils.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
INC_FILES = include/fdf.h

NAME = fdf

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
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
	@echo "  ______  _ ______ " 
	@echo " |  ____|| |  ____|"
	@echo " | |__ __| | |__   " 
	@echo " |  __/ _  |  __|  " 
	@echo " | | | (_| | |     " 
	@echo " |_|  \__,_|_|     " 
	@echo $(_END)

.PHONY: all clean fclean re ascii
