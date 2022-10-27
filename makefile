NAME = minishell
USERNAME = ${USER}
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
CC = gcc -g 
OBJ = ${SRCS:.c=.o}
SRCS = main.c parsing.c env.c link_list_cmd.c builtin.c dobble_quote.c nodes.c \
exec.c exit.c unset.c echo.c utils.c signals.c parsing_dobble_pipe.c parsing_pipe_in_quote.c parsing_quote.c \
parsing_space_beetween_pipe.c parsing_quote_no_pair.c export.c new.c check_error.c list_to_array.c split2.c export_utils.c
LIBFT = ./libft 
LIBFT_A = ./libft/libft.a

RDLINC    =    -I/Users/${USERNAME}/.brew/opt/readline/include
LIBRDL =    -L/Users/${USERNAME}/.brew/opt/readline/lib -lreadline

all : ${NAME}

${NAME} : ${OBJ}
	@$(MAKE) -C ${LIBFT}
	@${CC} ${CFLAGS} ${LIBRDL} -lreadline -o ${NAME} ${OBJ} ${RDLINC} ${LIBFT_A}

clean :
	rm -rf ${OBJ}
	rm -rf ${NAME}
	@make -C ${LIBFT} clean

fclean : clean
	rm -rf ${NAME}

re : fclean all