/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:25:01 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/16 14:57:05 by qbonvin          ###   ########.fr       */
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

/*
Link list for environnement
*/
typedef struct	s_env
{
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct	s_shell
{
	t_env	*env;
}	t_shell;

void	print_env(t_env *env);
int		init_env(t_env **new_env, char **envp);
t_env	*add_list(t_env *list, char *date);
t_env	*create_cell(char *data);
t_env	*empty_list(void);
int		isempty(t_env *L);
void	split_argument(int argc, char **argv);




#endif
