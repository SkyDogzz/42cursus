CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99

_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_GREY=\033[30m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

_IGREY=\033[40m
_IRED=\033[41m
_IGREEN=\033[42m
_IYELLOW=\033[43m
_IBLUE=\033[44m
_IPURPLE=\033[45m
_ICYAN=\033[46m
_IWHITE=\033[47m

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

SRC_NUM = num/ft_atoi.c num/ft_itoa.c

SRC_STR = str/ft_split.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c \
		  str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c \
		  str/ft_strmapi.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c \
		  str/ft_strtrim.c str/ft_substr.c 

SRC_FT_PRINTF = ft_printf/ft_printf.c ft_printf/ft_option.c \
				ft_printf/ft_parse.c ft_printf/ft_store.c \
				ft_printf/ft_printf_utils.c ft_printf/ft_util.c \
				ft_printf/ft_c.c ft_printf/ft_s.c ft_printf/ft_p.c \
				ft_printf/ft_d.c ft_printf/ft_u.c ft_printf/ft_xX.c \
				ft_printf/ft_color.c

SRC_GET_NEXT_LINE = get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

SRC_FILES = $(SRC_CHAR) $(SRC_FD) $(SRC_LST) $(SRC_NUM) $(SRC_MEM) \
			$(SRC_FT_PRINTF) $(SRC_GET_NEXT_LINE)

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^
	@echo "$(_BOLD)$(_UNDER)$(_CYAN)$(NAME) created!$(_END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(_BLUE)$(NAME)$@ created using $<$(_END)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_BOLD)$(_UNDER)$(_CYAN)Objects removed!$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_BOLD)$(_UNDER)$(_CYAN)$(NAME) removed!$(_END)"

re: fclean all

