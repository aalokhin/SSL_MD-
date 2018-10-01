# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 12:47:15 by aalokhin          #+#    #+#              #
#    Updated: 2018/06/14 12:47:19 by aalokhin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

F =  -Wall -Wextra -Werror

O := $(patsubst %.c,%.o,$(wildcard ./*.c))

all: $(NAME)

%.o: %.c
		@gcc -c $? $(FILES) $(F)

BLUE		=	\033[0;94m
YELLOW		=	\033[0;33m
LIGHT 		= 	\033[0;5m
COLOR_OFF	= 	\033[0m

$(NAME): $(O)
	@echo "$(YELLOW)compiling..."
	@make -C libft
	@gcc $(F) $(O) libft/libft.a  -o $(NAME)
	@echo "$(LIGHT)ft_ssl is ready"

clean:
	@echo "$(BLUE)deleting object files...$(COLOR_OFF)"
	@make clean -C ./libft/ 
	@rm -f $(O)
cleanlib:
	@echo "$(BLUE)deleting objects files in libft/ft_printf...$(COLOR_OFF)"
	@make clean -C ./libft/ 
fcleanlib:
	@make fclean -C ./libft/
fclean: clean fcleanlib
	@echo "$(BLUE)deleting exe_files and libraries...$(COLOR_OFF)"
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean fcleanlib cleanlib
