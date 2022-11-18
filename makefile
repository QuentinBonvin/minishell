NAME = minishell
USERNAME = ${USER}
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
CC = gcc -g 
OBJ = ${SRCS:.c=.o}
SRCS = main.c parsing.c env.c link_list_cmd.c builtin.c nodes.c \
exec.c exit.c unset.c echo.c utils.c signals.c parsing_quote.c bins.c \
export.c check_error.c list_to_array.c split2.c export_utils.c parsing_pipe.c \
execute.c redirections.c echo_utils.c utils2.c parsing_redirection.c \
builtin_utils.c export_utils2.c execute_utils.c error.c detect_chev.c dollar.c \
split_space.c exec_utils.c
LIBFT = ./libft 
LIBFT_A = ./libft/libft.a

RDLINC    =    -I/Users/${USERNAME}/.brew/opt/readline/include
LIBRDL =    -L/Users/${USERNAME}/.brew/opt/readline/lib -lreadline

all : ${NAME}
	@echo "\033[0;32m ==== MINISHELL CREATED ==== "
	@echo "\033[0m"

${NAME} : ${OBJ}
	@${MAKE} -C ${LIBFT}
	@${CC} ${CFLAGS} ${LIBRDL} -lreadline -o ${NAME} ${OBJ} ${RDLINC} ${LIBFT_A} 

clean :
	@echo "==== Clean all ===="
	rm -rf ${OBJ}
	@rm -rf ${NAME}
	@make -C ${LIBFT} clean

fclean : clean
	@rm -rf ${NAME}	

re : fclean all