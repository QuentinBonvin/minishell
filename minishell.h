#ifndef MINISHELL_H
# define MINISHELL_H
# define SIMPLE_QUOTE 39
# define DOBBLE_QUOTE 34
# define PIPE 124
# define TOK_DELIM "|"

# include "./libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

/*************************************************
Link list for environnement
*************************************************/
typedef struct s_env
{
	char				*content;
	struct s_env		*next;
	struct s_env		*prev;
}	t_env;

/*************************************************
Link list for cmd
*************************************************/
typedef struct s_cmd
{
	char				*content;
	struct s_cmd		*next;
	struct s_cmd		*prev;
}	t_cmd;

typedef struct s_shell
{
	t_env			*node;
	char			*token;
	int				single_quote;
	int				double_quote;
	t_cmd			*cmd;
	t_cmd			*head;
	t_cmd			*tail;
	t_env			*env_head;
	t_env			*env_tail;
}	t_shell;

/*************************************************
Link list function for environnement
*************************************************/
// t_env			*create_cell(char **envp);
void			*create_cell(t_env **env_head, t_env **env_tail, char **envp);
void			init_env(char **envp, t_shell *list);
void			printf_env(t_shell *list);
// t_env			*add_envp_to_env(t_env *env, char **envp/*, int i*/);
void			*add_envp_to_env(t_env **head, char **envp);

/*************************************************
Link list function for cmd
*************************************************/	
t_cmd			*create_cmd(char *token);
t_cmd			*add_cmd_to_list(t_cmd *list, char *token);
void			printf_cmd(t_shell *list);

/*************************************************
function for parsing
*************************************************/
int				parsing_line(char *line, t_shell *list);
void			split_with_pipe(char *line, t_shell *list);
void			split_with_double_quote(char *line, t_shell *list);
void			split_with_single_quote(char *line, t_shell *list);
char			*my_strtok(char *str, char *delim);
unsigned int	is_delim(char c, char *delim);
int				dobble_quote(char *line);
int				check_if_another_dobble_quote(char *line);
int				check_quote(char *line, int position, char c);
int				nbr_quote(char *line);
int				pipe_in_quote(char *line);
int				string_search(char *line, char c);
int				check_error(char *line);
int				pipe_at_start_or_end(char *line);
int				only_one_simple_or_dobble_quote(char *line);
int				is_dobble_pipe(char *line);
int				space_after_pipe(char *line);
int				nbr_pipe_in_string(char *line);



// void	print_env(t_content_env *env);
// int		init_env(t_content_env **new_env, char **envp);
// t_content_env	*add_list(t_content_env *list, char *date);
// t_content_env	*create_cell(char *data);
// t_content_env	*empty_list(void);
// int		isempty(t_content_env *L);

/*************************************************
Link list function for builtins
*************************************************/	
int				builtin(char *line, t_shell *list);
int				ft_strcmp(char *s1, char *s2);

void			start_stack(t_cmd **head, t_cmd **tail, char *token);
void			insert_beginning(t_cmd **tail, char *token);
void			sig_handler(int signum);
void			sig_quit(int signum);
void			rl_replace_line(char *text, int clear_undo);
void			check_line(char *line, t_shell *list);

#endif
