# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 16:22:29 by qbonvin           #+#    #+#              #
#    Updated: 2022/03/14 17:25:07 by qbonvin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Declaration de mes variables
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
ft_formator.c ft_len_number.c ft_printf.c ft_putchar.c ft_putnbr.c \
ft_putnbr_hexa_maj.c ft_putnbr_hexa_min.c ft_putnbr_unsigned.c ft_putstr.c \
ft_uitoa.c get_next_line.c ft_strjoin_gnl.c ft_strchr_gnl.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = ${SRCS:.c=.o}
# fin de la declatation des variables

all : ${NAME}

${NAME} : ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

bonus : ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean re all
