NAME = libftprintf.a
CC = gcc
SRC =	conversion_utils.c \
		ft_printf.c \
		ft_parse_printf.c \
		string_utils.c

CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all