NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS_CHAR = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		 ft_toupper.c ft_tolower.c

SRCS_STR = ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
		  ft_strlcat.c ft_strnstr.c ft_atoi.c

SRCS_MEM = ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		  ft_bzero.c

SRCS_MAL = ft_calloc.c ft_strdup.c

SRCS_MORE = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c

SRCS = $(SRCS_CHAR) $(SRCS_STR) $(SRCS_MEM) $(SRCS_MAL) $(SRCS_MORE)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
