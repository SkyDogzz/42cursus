CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC_CHAR = char/ft_isalnum.c char/ft_isalpha.c char/ft_isascii.c \
		   char/ft_isdigit.c char/ft_isprint.c char/ft_isspace.c

SRC_NUM = num/ft_atoi.c

SRC_MEM = mem/ft_bzero.c

SRC_FILES = $(SRC_CHAR) $(SRC_NUM) $(SRC_MEM) mem/ft_calloc.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

