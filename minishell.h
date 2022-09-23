/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:25:01 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/23 11:25:09 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

/*************************************************
Link list for environnement
*************************************************/
typedef struct	s_node_env
{
	char					*content;
	struct s_node_env		*next;
}	t_node_env;

typedef struct	s_list_env
{
	t_node_env	*first_node;
}	t_list_env;

/*************************************************
Link list for cmd
*************************************************/
typedef struct	s_node_cmd
{
	char					*content;
	struct s_node_cmd		*next;
}	t_node_cmd;

typedef struct	s_list_cmd
{
	t_node_cmd	*first_node;
}	t_list_cmd;

typedef struct	s_shell
{
	t_node_env		*node;
	t_node_cmd		*cmd;
}	t_shell;

/*************************************************
Link list function for environnement
*************************************************/
t_list_env	*create_env(char **envp);
void		init_env(char **envp);
void 		printf_env(t_list_env *list);
void		add_envp_to_env(t_list_env *env, char **envp, int i);

/*************************************************
Link list function for cmd
*************************************************/
t_list_cmd	*create_cmd();
void		add_cmd_to_list(t_list_cmd *cmd, char *line);

void		parsing_line(char *line);
char		*split_with_pipe(char *line);


// void	print_env(t_content_env *env);
// int		init_env(t_content_env **new_env, char **envp);
// t_content_env	*add_list(t_content_env *list, char *date);
// t_content_env	*create_cell(char *data);
// t_content_env	*empty_list(void);
// int		isempty(t_content_env *L);




#endif
