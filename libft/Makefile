
NAME = libft.a

OBJ := $(patsubst %.c,%.o,$(wildcard ./*.c))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(OBJ): %.o:%.c
	@gcc -Wall -Werror -Wextra -c -o $@ $<
