# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 15:05:41 by qbonvin           #+#    #+#              #
#    Updated: 2022/09/19 15:54:29 by qbonvin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
CC = gcc -g 
OBJ = ${SRCS:.c=.o}
SRCS = main.c parsing.c env.c
LIBFT = ./libft 
LIBFT_A = ./libft/libft.a

all : ${NAME}

${NAME} : ${OBJ}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} -lreadline -o ${NAME} ${OBJ} ${LIBFT_A}

clean :
	rm -rf ${OBJ}
	rm -rf ${NAME}
	make -C ${LIBFT} clean

fclean : clean
	rm -rf ${NAME}

re : fclean all