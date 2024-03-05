FUNC = ft_chars.c ft_numbers.c\
	ft_printf.c

CC = gcc -Wall -Wextra -Werror
NAME = libftprintf.a
OBJETS = $(FUNC:.c=.o)

all: $(NAME)

$(NAME): $(OBJETS)
	ar rc $(NAME) $(OBJETS)

$(OBJETS): $(FUNC)
	$(CC) -c $(FUNC) -I .

clean:
	rm -f $(OBJETS) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(OBJ_BNS)

re: fclean all