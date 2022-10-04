NAME = minishell
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
CC = gcc -g 
OBJ = ${SRCS:.c=.o}
SRCS = main.c parsing.c env.c link_list_cmd.c test2.c builtin.c dobble_quote.c test_list.c \
utils.c
LIBFT = ./libft 
LIBFT_A = ./libft/libft.a

RDLINC    =    -I/Users/nnemeth/.brew/opt/readline/include
LIBRDL =    -L/Users/nnemeth/.brew/opt/readline/lib -lreadline

all : ${NAME}

${NAME} : ${OBJ}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} ${LIBRDL} -lreadline -o  ${NAME} ${OBJ} ${RDLINC} ${LIBFT_A}

clean :
	rm -rf ${OBJ}
	rm -rf ${NAME}
	make -C ${LIBFT} clean

fclean : clean
	rm -rf ${NAME}

re : fclean all