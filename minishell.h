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
# include <termios.h>

// struct termios saved;
// struct termios attributes;

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
	char				**tab;
	struct s_cmd		*next;
	struct s_cmd		*prev;
}	t_cmd;

typedef struct s_shell
{
	t_env			*node;
	char			*token;
	int				single_quote;
	int				end;
	int				start;
	int				index;
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
void			split_with_pipe1(char *line, t_shell *list);
t_shell			*split_with_double_quote(char *line, t_shell *list);
t_shell			*split_with_single_quote(char *line, t_shell *list);
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
int				quote_have_no_pair(char *line);
int				check_if_dobble_quote_is_pair(char *line);
int				check_if_single_quote_is_pair(char *line);
int				quote_inside_dobble_quote(char *line);
int				quote_inside_simple_quote(char *line);
int				check_if_letter_beetween_pipe(char *line);
int				pipe_in_single_quote(char *line);
int				check_dobble_pipe_before_quote(char *line);
int				check_only_dobble_pipe(char *line);
int				last_check_dobble_pipe(char *line);
void			ctrl_c_signal(int signum);
void			ctrl_d_signal(int signum);
void			handle_signal(struct termios *saved);
void 			hide_keystrokes(struct termios *attr);
void    		splitting_with_space(char *line, t_shell *list);
int    			no_quote_or_no_pipe(char *line);



// void	print_env(t_content_env *env);
// int		init_env(t_content_env **new_env, char **envp);
// t_content_env	*add_list(t_content_env *list, char *date);
// t_content_env	*create_cell(char *data);
// t_content_env	*empty_list(void);
// int		isempty(t_content_env *L);

/*************************************************
Link list function for builtins
*************************************************/	
void			builtin(t_shell *list);
int				ft_strcmp(char *s1, char *s2);
char			*search_env(t_shell *list);
int				call_cd(t_shell *list, char *arg);
void			call_pwd(void);
int				call_unset(t_shell *list, char *var);
int				ft_strncmp2(char *s1, char *s2, int n);
void			ft_remove_from_list(t_shell *list, char *var);
int				ft_delete_first_node(t_env **env_head, t_env *curr, char *var);
void			mini_echo(t_shell *list, char *command);
int				ft_find_sign(char *command);
void			sort_list(t_shell *list, char *arg);
void			ft_swap(char *s1, char *s2);
t_env			*ft_copy(t_env *curr, t_shell *list);
int				ft_count_env(t_shell *list);
int				ft_count_copy(char **env_array);
t_env			*create_node(char *node);
void			print_list(t_env *copy);
char			*get_env(char *name, t_shell *list);
char			*join_home(char *curr, int length);
char			*env_ok(char *name, t_shell *list);
int				set_env(char *name, char *pwd, t_shell *list);
int				check_arg(char *arg);
void			add_to_env_copy(t_shell *list, char **env_array, char *arg, int l);
void			print_new_env(char **env_array, int len);
void			*add_export_to_env(t_env **env_tail, char *arg);
char			*check_if_in_env(t_shell *list, char *arg);
void			replace_in_env(t_shell *list, char *env, char *arg);
void			mini_exit(t_shell *list, char *arg);

/*************************************************
Link list function for linked list
*************************************************/	

void			*start_stack(t_cmd **head, t_cmd **tail, char *token);
void			*insert_beginning(t_cmd **tail, char *token);
void			rl_replace_line(char *text, int clear_undo);
t_shell			*check_line(char *line, t_shell *list);
// void			remove_node(t_node *node);
void			free_cmd(t_shell *list);
void			free_env(t_shell *list);
void			remove_node(t_cmd *node);
void			free_tab(char **env);
char 			**convert_list(t_shell *list);
void			print_array(char **env_array, int len);
void		    init_list(t_shell *list);
int				string_start(char *line, char c);
void			list_to_array(t_shell *list);
void			ft_split2(char const *line, char c, t_shell *list);
void			ft_split2_to_long(const char *line, size_t i);
int				ft_compare(const char *s1, const char *s2);
void			sort_and_swap(char **env_array, int l);

#endif
