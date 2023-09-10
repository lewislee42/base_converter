# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 09:27:44 by lewlee            #+#    #+#              #
#    Updated: 2023/06/06 14:24:36 by lewlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCSB =  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCPRINTF = ./ft_printf/srcs/ft_printf.c ./ft_printf/srcs/ft_printf_puts.c
SRCS_EXTRAS = ft_strndup.c ./gnl/get_next_line_bonus.c ./gnl/get_next_line_utils_bonus.c
FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)
OBJB = $(SRCSB:.c=.o)
OBJPRINTF = $(SRCPRINTF:.c=.o)
OBJ_EXTRAS = $(SRCS_EXTRAS:.c=.o)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./ft_printf
	ar rcs $(NAME) $(OBJ) $(OBJPRINTF)

bonus: $(NAME) $(OBJB) $(OBJ_EXTRAS)
	make -C ./ft_printf
	ar rcs $(NAME) $(OBJB) $(OBJ_EXTRAS)

clean:
	make clean -C ./ft_printf
	rm -rf $(OBJ) $(OBJB) $(OBJ_EXTRAS)

fclean: clean
	make fclean -C ./ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY = clean fclean re all bonus