# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lewlee <lewlee@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 06:35:47 by lewlee            #+#    #+#              #
#    Updated: 2023/09/10 06:47:41 by lewlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = base_converter
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
LIBFT = -I./libft -L ./libft -lft
OBJ = $(SRCS:.c=.o)

%.o: %.c
	gcc $(LIBFT) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re