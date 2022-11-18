/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:30:46 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 16:41:15 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_to_array(t_shell *list, t_env *env)
{
	t_cmd	*tmp;
	int		i;
	int		j;

	i = 0;
	(void)env;
	j = 0;
	tmp = list->head;
	while (tmp != NULL)
	{
		ft_split_space(tmp->content, ' ', tmp);
		free(tmp->content);
		tmp = tmp->prev;
	}
	tmp = list->head;
	while (tmp)
	{
		i = 0;
		while (tmp->tab[i])
		{
			i++;
		}
	tmp = tmp->prev;
	}
}

char	what_quote(char *data)
{
	int	j;
	int	quote;
	int	i;

	j = 0;
	i = 0;
	quote = 0;
	while (data[i])
	{
		if (data[i] == '\'')
			return (1);
		else if (data[i] == '\"')
			return (2);
		else if (data[i] != '\'' && data[i] != '\"')
			i++;
	}
	return (3);
}

int	return_value(t_shell *list, char **command)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = list->head;
	while (command[i])
	{
		if (ft_strcmp(command[i], "$?") == 0)
		{
			free(command[i]);
			command[i] = ft_itoa(g_exit_status);
		}
		i++;
	}
	return (g_exit_status);
}

void	list_to_array2(t_shell *list, int j, int space, t_cmd *tmp)
{
	while (tmp->content[j])
	{
		if (what_quote(&tmp->content[j]) == 1 && space > 0)
		{
			list->single_quote = 1;
			tmp->tab = ft_split(tmp->content, '\'');
			break ;
		}
		else if (what_quote(&tmp->content[j]) == 2 && space > 0)
		{
			list->double_quote = 1;
			tmp->tab = ft_split(tmp->content, '\"');
			break ;
		}
		else if (what_quote(&tmp->content[j]) == 3 || space == 0)
		{
			tmp->tab = ft_split(tmp->content, ' ');
			break ;
		}
		j++;
	}
}
