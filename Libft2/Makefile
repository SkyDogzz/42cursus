CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99

_END=$(shell printf "\033[0m")
_BOLD=$(shell printf "\033[1m")
_UNDER=$(shell printf "\033[4m")
_CYAN=$(shell printf "\033[36m")
_BLUE=$(shell printf "\033[34m")

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC_CHAR = char/ft_isalnum.c char/ft_isalpha.c char/ft_isascii.c \
		   char/ft_isdigit.c char/ft_isprint.c char/ft_isspace.c \
		   char/ft_tolower.c char/ft_toupper.c

SRC_FD = fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c \
		 fd/ft_putstr_fd.c

SRC_LST = lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c \
		  lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c lst/ft_lstmap.c \
		  lst/ft_lstnew.c lst/ft_lstsize.c

SRC_MEM = mem/ft_bzero.c mem/ft_calloc.c mem/ft_memchr.c mem/ft_memcmp.c \
		  mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c

SRC_NUM = num/ft_abs.c num/ft_atoi.c num/ft_itoa.c num/ft_atoi_base.c

SRC_STR = str/ft_split.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c \
		  str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c \
		  str/ft_strmapi.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c \
		  str/ft_strtrim.c str/ft_substr.c 

SRC_UTILS = utils/ft_gettotal.c

SRC_LIBFT_BASE = $(SRC_CHAR) $(SRC_FD) $(SRC_LST) $(SRC_NUM) $(SRC_MEM) \
				 $(SRC_STR) $(SRC_UTILS)

SRC_FT_PRINTF = ft_printf/ft_printf.c ft_printf/ft_option.c \
				ft_printf/ft_parse.c ft_printf/ft_store.c \
				ft_printf/ft_printf_utils.c ft_printf/ft_util.c \
				ft_printf/ft_c.c ft_printf/ft_s.c ft_printf/ft_p.c \
				ft_printf/ft_d.c ft_printf/ft_u.c ft_printf/ft_xX.c \
				ft_printf/ft_color.c

SRC_GET_NEXT_LINE = get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

OBJ_LIBFT_BASE = $(addprefix $(OBJ_DIR)/, $(SRC_LIBFT_BASE:.c=.o))
OBJ_FT_PRINTF = $(addprefix $(OBJ_DIR)/, $(SRC_FT_PRINTF:.c=.o))
OBJ_GET_NEXT_LINE = $(addprefix $(OBJ_DIR)/, $(SRC_GET_NEXT_LINE:.c=.o))

NAME = libft.a

ascii:
	@echo $(_CYAN)$(_BOLD)
	@echo " _      _____ ______ ______  _____ " 
	@echo "| |    |_   _|| ___ \|  ___||_   _|"
	@echo "| |      | |  | |_/ /| |_     | |  " 
	@echo "| |      | |  | ___ \|  _|    | |  " 
	@echo "| |____ _| |_ | |_/ /| |      | |  " 
	@echo "\_____/ \___/ \____/ \_|      \_/  " 
	@echo $(_END)

all: ascii $(NAME)
	@echo "$(_CYAN)[BUILD COMPLET]$(_END) $(NAME) est prêt !"

$(NAME): $(OBJ_LIBFT_BASE) $(OBJ_FT_PRINTF) $(OBJ_GET_NEXT_LINE)
	@ar rcs $@ $^
	@echo "$(_CYAN)[ARCHIVE]$(_END) Ajout des fichiers objets dans $(_BOLD)$(NAME)$(_END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(_CYAN)[COMPILATION]$(_END) Création de l'objet : $(_BOLD)$@$(_END)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_BLUE)[CLEAN]$(_END) Suppression des fichiers objets."

fclean: clean lclean
	@rm -f $(NAME)
	@echo "$(_BLUE)[FCLEAN]$(_END) Suppression de l'archive $(NAME)."

re: fclean all

lint: all
	@mkdir -p $(LOG_DIR)
	@cppcheck --enable=all --inconclusive --std=c99 -I include/ src/ \
	--suppress=unusedFunction --suppress=unusedVariable \
	--suppress=variableScope --suppress=missingIncludeSystem \
	--check-level=exhaustive --suppress=unmatchedSuppression \
	--suppress=shiftTooManyBitsSigned \
	--suppress=checkersReport 2> $(LOG_DIR)/lint_errors.log
	@echo "$(_CYAN)Résultats de cppcheck enregistrés dans lint_errors.log$(_END)"

TEST_DIR = tests
TEST_SRC = $(TEST_DIR)/main.c $(TEST_DIR)/src/libft/char.c
TEST_BIN = test_libft

LOG_DIR = log

lclean:
	@rm -rf $(LOG_DIR) $(TEST_BIN)

tests: $(NAME) $(TEST_SRC)
	@rm -rf $(TEST_BIN)
	@mkdir -p $(LOG_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(TEST_SRC) $(NAME) -o $(TEST_BIN)
	@echo "$(_BOLD)$(_UNDER)$(_CYAN)Exécution des tests !$(_END)"
	./$(TEST_BIN)

.PHONY: tests
