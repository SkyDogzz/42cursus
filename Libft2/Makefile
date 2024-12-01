CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99 -O2 -march=native -flto -MMD
LDFLAGS = -flto

_END    = $(shell printf "\033[0m")
_BOLD   = $(shell printf "\033[1m")
_CYAN   = $(shell printf "\033[36m")
_BLUE   = $(shell printf "\033[34m")

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LOG_DIR = log

SRC_LIBFT_BASE = \
	char/ft_isalnum.c char/ft_isalpha.c char/ft_isascii.c \
	char/ft_isdigit.c char/ft_isprint.c char/ft_isspace.c \
	char/ft_tolower.c char/ft_toupper.c char/ft_isblank.c \
	char/ft_islower.c char/ft_isupper.c char/ft_swapcase.c \
	fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c \
	fd/ft_putstr_fd.c \
	lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c \
	lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c lst/ft_lstmap.c \
	lst/ft_lstnew.c lst/ft_lstsize.c \
	mem/ft_bzero.c mem/ft_calloc.c mem/ft_memchr.c mem/ft_memcmp.c \
	mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c \
	num/ft_abs.c num/ft_atoi.c num/ft_itoa.c num/ft_atoi_base.c \
	str/ft_split.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c \
	str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c \
	str/ft_strmapi.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c \
	str/ft_strtrim.c str/ft_substr.c \
	utils/ft_gettotal.c \
	ft_printf/ft_printf.c ft_printf/ft_option.c \
	ft_printf/ft_parse.c ft_printf/ft_store.c \
	ft_printf/ft_printf_utils.c ft_printf/ft_util.c \
	ft_printf/ft_c.c ft_printf/ft_s.c ft_printf/ft_p.c \
	ft_printf/ft_d.c ft_printf/ft_u.c ft_printf/ft_xX.c \
	ft_printf/ft_color.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_LIBFT_BASE:.c=.o))
DEP_FILES = $(OBJ_FILES:.o=.d)

NAME = libft.a

all: ascii $(NAME)
	@echo "$(_CYAN)[BUILD COMPLET]$(_END) $(NAME) est prêt !"

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^
	@echo "$(_CYAN)[ARCHIVE]$(_END) Ajout des fichiers objets dans $(_BOLD)$(NAME)$(_END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_CYAN)[COMPILATION]$(_END) Création de l'objet : $(_BOLD)$@$(_END)"

-include $(DEP_FILES)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_BLUE)[CLEAN]$(_END) Suppression des fichiers objets."

fclean: clean
	@rm -f $(NAME)
	@echo "$(_BLUE)[FCLEAN]$(_END) Suppression de l'archive $(NAME)."

re: fclean all

ascii:
	@echo $(_CYAN)$(_BOLD)
	@echo " _      _____ ______ ______  _____ " 
	@echo "| |    |_   _|| ___ \|  ___||_   _|"
	@echo "| |      | |  | |_/ /| |_     | |  " 
	@echo "| |      | |  | ___ \|  _|    | |  " 
	@echo "| |____ _| |_ | |_/ /| |      | |  " 
	@echo "\_____/ \___/ \____/ \_|      \_/  " 
	@echo $(_END)

lint:
	@mkdir -p $(LOG_DIR)
	@cppcheck --enable=all --inconclusive --std=c99 -I $(INC_DIR) $(SRC_DIR) \
	--suppress=unusedFunction --suppress=unusedVariable \
	--suppress=variableScope --suppress=missingIncludeSystem \
	--check-level=exhaustive --suppress=unmatchedSuppression \
	--suppress=shiftTooManyBitsSigned \
	--suppress=checkersReport 2> $(LOG_DIR)/lint_errors.log
	@echo "$(_CYAN)Résultats de cppcheck enregistrés dans $(LOG_DIR)/lint_errors.log$(_END)"

.PHONY: all clean fclean re ascii lint
