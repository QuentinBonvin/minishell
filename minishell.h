/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:27:51 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/21 12:26:27 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <fcntl.h>
# include <errno.h>

// struct termios saved;
// struct termios attributes;

/*************************************************
Link list for environnement
*************************************************/
int	g_exit_status;

# define TRUE 1
# define FALSE 0

typedef struct s_env
{
	char				*content;
	struct s_env		*next;
	struct s_env		*prev;
	struct s_env		*env_head;
	struct s_env		*env_tail;
}	t_env;

/*************************************************
Link list for cmd
*************************************************/
typedef struct s_cmd
{
	int					redir_status;
	char				*content;
	char				*cmd;
	char				**tab;
	struct s_cmd		*next;
	struct s_shell		*list;
	int					fd_in;
	int					fd_out;
	pid_t				pid;
	struct s_cmd		*prev;
}	t_cmd;

typedef struct s_shell
{
	t_env				*node;
	char				*token;
	int					end;
	int					single_quote;
	int					double_quote;
	int					start;
	int					index;
	t_cmd				*cmd;
	t_cmd				*head;
	t_cmd				*tail;
}	t_shell;

/*************************************************
Link list function for environnement
*************************************************/
void			*create_cell(t_env **env_head, t_env **env_tail, char *envp);
void			init_env(char **envp, t_env *env);
int				printf_env(t_env *env, t_cmd *current);
// t_env			*add_envp_to_env(t_env *env, char **envp/*, int i*/);
void			*add_envp_to_env(t_env **head, char *envp);

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
int				check_data_to_lst(char *data);
int				is_double_pipe(char *data, int i);
int				after_is_quote(char *data, int i);
int				is_quote(char *data, int i);
int				is_s_quote(char *data, int i);
int				is_d_quote(char *data, int i);
int				check_space_beetween_pipe(char *data, int i);
int				first_char_is_pipe(char *line);
int				last_char_is_pipe(char *line);
int				pipe_at_start_or_end(char *line);
char			*split_space(t_shell *list, int c);
int				check_if_space_beewtween_quote(char *line, int index_space);
char			*string_after_trim(char *str, t_shell *list);
int				ft_split2_too_long(const char *line, int i);
int				detect_chev(int i, t_cmd *curr);
int				check_data_to_lst(char *data);
int				is_double_pipe(char *data, int i);
int				after_is_quote(char *data, int i);
int				is_quote(char *data, int i);
int				is_s_quote(char *data, int i);
int				is_d_quote(char *data, int i);
int				check_space_beetween_pipe(char *data, int i);
int				first_char_is_pipe(char *line);
int				last_char_is_pipe(char *line);
int				pipe_at_start_or_end(char *line);
char			*split_space(t_shell *list, int c);
int				check_if_space_beewtween_quote(char *line, int index_space);
char			*string_after_trim(char *str, t_shell *list);
int				ft_split2_too_long(const char *line, int i);
int				check_pipe(char *data, int i);
int				check_another_quote(char *data, int i);
int				detect_one_chev_input(int i, t_cmd *curr);
int				detect_two_chev_input(int i, t_cmd *curr);
int				detect_one_chev_output(int i, t_cmd *curr);
int				detect_two_chev_output(int i, t_cmd *curr);
void			delete_empty_tab(t_shell *list);
int				only_space(char *line);
int				count_space(char *line);
void			own_heredocs_to_long(char *delimiter, char *line, int *fd,
					t_cmd *curr);
void			list_to_array2(t_shell *list, int j, int space, t_cmd *tmp);

/*************************************************
Signal
*************************************************/	
void			ctrl_c_signal(int signum);
void			handle_signal(struct termios *saved);
void			hide_keystrokes(struct termios *attr);
void			handle_sigquit(int signal);
/*************************************************
Exec bins
*************************************************/	
char			**bins(t_cmd *cmd, t_env *env);
void			bins_execute(char **split_path, char **envp, t_cmd *cmd);
void			free_split_path(char **split_path);
void			free_tab_cmd(t_shell *list);
int				command_not_found(t_cmd *curr, char **envp);
int				ft_strcmp_env(char *s1, char *s2);
void			start_bins(t_cmd *current, t_env *env,
					char **envp, char **execute);

/*************************************************
Link list function for builtins
*************************************************/	
int				exec_builtin(t_cmd *current, t_shell *list,
					char *line, t_env *env);
int				builtin(t_shell *list, char **envp, char *line);
int				call_pwd(void);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp2(char *s1, char *s2, int n);
int				call_cd(t_cmd *current, t_env *env);
int				ft_error(char **arg);
int				set_env(char *name, char *pwd, t_env *env);
char			*get_env(char *name, t_env *env);
char			*join_home(char *curr, int length);
int				mini_echo(t_cmd *current, char **command, t_shell *list);
void			printer(char *command, t_shell *list);
int				print_echo(t_cmd *current, int i, int option, t_shell *list);
void			execute_dollar(t_shell *list, int i,
					int option, char **command);
void			check_dollar(char **command, int option, t_shell *list);
int				index_check(t_shell *list, int option, int i);
int				ft_find_sign(char *command);
char			*dollar_var(t_shell *list, char *var, t_env *env);
int				sort_list(t_env *env, char **arg);
char			**convert_list(t_env *env);
int				ft_count_env(t_env *env);
void			sort_and_swap(char **env_array, int l);
void			print_array(t_env *env);
char			*check_if_in_env(t_env *env, char *arg);
void			replace_in_env(t_env *env, char *envp, char *arg);
void			*add_export_to_env(t_env **env_tail, char *arg);
int				check_arg(char *arg);
int				ft_compare(const char *s1, const char *s2);
void			*free_env_array(char **env_array);
t_env			*ft_copy(t_env *curr, t_env *env);
t_env			*create_node(char *node);
char			*search_env(t_env *env);
int				call_unset(t_env *env, char **var);
void			ft_remove_from_list(t_env *env, char *var);
int				ft_delete_first_node(t_env **env_head, t_env *curr, char *var);
void			print_list(t_env *copy);
int				mini_exit(t_cmd *current, char *arg, char *line, t_env *env);

/*************************************************
Link list function for linked list
*************************************************/	

void			*start_stack(t_cmd **head, t_cmd **tail, char *token);
void			*insert_beginning(t_cmd **tail, char *token);
void			rl_replace_line(char *text, int clear_undo);
t_shell			*check_line(char *line, t_shell *list, t_env *env);
void			free_cmd(t_shell *list);
void			free_env(t_env *env);
void			remove_node(t_cmd *node);
void			free_tab(char **env);
void			init_list(t_shell *list);
int				string_start(char *line, char c);
void			list_to_array(t_shell *list, t_env *env);
void			ft_split2(char const *line, char c, t_shell *list);
void			exec_with_pipe(t_shell *list, char **envp,
					char *line, t_env *env);
void			exec(t_shell *list, char **envp, char *line, t_env *env);
int				is_redir(t_shell *list);
int				simple_output(t_cmd *curr, int i);
void			delete_chev(t_cmd *list, int i);
int				dobble_output(t_cmd *curr, int i);
int				simple_input(t_cmd *curr, int i);
int				own_heredocs(t_cmd *curr, int i);
int				is_a_chevron(t_cmd *curr, int i);
void			init_pipe(t_shell *list);
void			close_pipe(t_shell *list);
void			wait_pipe(t_shell *list);
void			find_dollar(t_shell *list, t_env *env);
int				void_argv_argc(int argc, char **argv);
int				prompt(t_shell *list, char **envp,
					struct termios *saved, t_env *env);
char			what_quote(char *data);
void			trim_quote(t_shell *list);
void			free_all(t_shell *list, t_env *env, char *line);
int				check_command_not_found(int i, char **envp, t_cmd *curr);
int				return_value(t_shell *list, char **command);
int				ft_equal(char **arg, int i, int j, t_env *env);
int				get_direction(char *arg, char *home, t_cmd *curr);
int				bin_exec(char *tmp2, char **tab, char **envp);
void			replace_value(char *arg, int j, t_env *env);
void			add_new(t_env *env, char *arg);
int				is_equal(char *arg, int j);
void			combine(char *arg, t_env *env);
int				print_and_return(t_cmd *current, int i, int option,
					t_shell *list);
int				ft_error_print(char **arg);
int				swap_tab(char **str, int i);
void			detect_dollar(t_shell *list, char **str, t_env *env);
void			no_home(char **split_path, t_cmd *curr, int i);
int				home_not_set(char *home, char *pwd);
void			ft_split_space(char *line, char c, t_cmd *curr);
int				ft_set(char *s, char c);

#endif