# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tremy <tremy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 16:26:49 by tremy             #+#    #+#              #
#    Updated: 2023/12/07 16:03:09 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRC			=	$(shell ls *.c) $(shell ls utils/*.c) $(shell ls builtins/*.c) $(shell ls parsing/*.c) $(shell ls decidomatic/*.c) $(shell ls redirections/*.c)

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra -gdwarf-4

OBJ			=	$(SRC:.c=.o)

.c.o =			clang $(CFLAGS) -c $< -o $(<:.c=.o)

${NAME}:	${OBJ}
			@make -s -C libft
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline

all:		$(NAME)

clean:
			rm -f $(OBJ)
fclean:		clean
			rm -f $(NAME)
			rm -f tastyshell

re:			fclean all
