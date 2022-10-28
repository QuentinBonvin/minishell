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
int				string_search(char *line, char c);
int				check_error(char *line);

/*************************************************
function for parsing
*************************************************/
int		check_data_to_lst(char *data);
int		is_double_pipe(char *data, int i);
int		after_is_quote(char *data, int i);
int		is_quote(char *data, int i);
int		is_s_quote(char *data, int i);
int		is_d_quote(char *data, int i);
int		check_space_beetween_pipe(char *data, int i);
int		first_char_is_pipe(char *line);
int 	last_char_is_pipe(char *line);
int		pipe_at_start_or_end(char *line);

/*************************************************
Signal
*************************************************/	
void			ctrl_c_signal(int signum);
void			ctrl_d_signal(int signum);
void			handle_signal(struct termios *saved);
void 			hide_keystrokes(struct termios *attr);
/*************************************************
Exec bins
*************************************************/	
void	bins(t_shell *list, char **envp);
void	bins_execute(char **split_path, t_shell *list, char **envp);
void	free_split_path(char **split_path);
void	free_tab_cmd(t_shell *list);


// void	print_env(t_content_env *env);
// int		init_env(t_content_env **new_env, char **envp);
// t_content_env	*add_list(t_content_env *list, char *date);
// t_content_env	*create_cell(char *data);
// t_content_env	*empty_list(void);
// int		isempty(t_content_env *L);

/*************************************************
Link list function for builtins
*************************************************/	
void			builtin(t_shell *list, char **envp);
void			call_pwd(void);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp2(char *s1, char *s2, int n);
int				call_cd(t_shell *list);
void			ft_error_cd(char *arg);
int				set_env(char *name, char *pwd, t_shell *list);
char			*get_env(char *name, t_shell *list);
char			*join_home(char *curr, int length);
void			mini_echo(t_shell *list, char *command);
int				print_echo(t_shell *list, int i, int option);
void			execute_dollar(t_shell *list, int i, int option, char *command);
int				ft_find_sign(char *command);
void			dollar_var(t_shell *list, char *var);
void			sort_list(t_shell *list, char *arg);
char 			**convert_list(t_shell *list);
int				ft_count_env(t_shell *list);
void			sort_and_swap(char **env_array, int l);
void			print_array(char **env_array, int len);
char			*check_if_in_env(t_shell *list, char *arg);
void			replace_in_env(t_shell *list, char *env, char *arg);
void			*add_export_to_env(t_env **env_tail, char *arg);
int				check_arg(char *arg);
int				ft_compare(const char *s1, const char *s2);
t_env			*ft_copy(t_env *curr, t_shell *list);
t_env			*create_node(char *node);
char			*search_env(t_shell *list);
int				call_unset(t_shell *list, char *var);
void			ft_remove_from_list(t_shell *list, char *var);
int				ft_delete_first_node(t_env **env_head, t_env *curr, char *var);
void			print_list(t_env *copy);
void			mini_exit(t_shell *list, char *arg);

/*************************************************
Link list function for linked list
*************************************************/	

void			*start_stack(t_cmd **head, t_cmd **tail, char *token);
void			*insert_beginning(t_cmd **tail, char *token);
void			rl_replace_line(char *text, int clear_undo);
t_shell			*check_line(char *line, t_shell *list);
void			free_cmd(t_shell *list);
void			free_env(t_shell *list);
void			remove_node(t_cmd *node);
void			free_tab(char **env);
void		    init_list(t_shell *list);
int				string_start(char *line, char c);
void			list_to_array(t_shell *list);
void			ft_split2(char const *line, char c, t_shell *list);
void			ft_split2_to_long(const char *line, size_t i);

/*normally can delete*/
// void			remove_node(t_node *node);
// void			print_new_env(char **env_array, int len);
// char			*env_ok(char *name, t_shell *list);
// void			add_to_env_copy(t_shell *list, char **env_array, char *arg, int l);
// void			ft_swap(char *s1, char *s2);
// int				ft_count_copy(char **env_array);

#endif
