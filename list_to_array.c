#include "minishell.h"

void	list_to_array(t_shell *list, t_env *env)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = list->head;
	while (tmp != NULL)
	{
		if (what_quote(tmp->content) == 1)
		{
			list->single_quote = 1;
			tmp->tab = ft_split(tmp->content, '\'');
		}
		else if (what_quote(tmp->content) == 2)
		{
			list->double_quote = 1;
			tmp->tab = ft_split(tmp->content, '\"');
		}
		else if (what_quote(tmp->content) == 3)
			tmp->tab = ft_split(tmp->content, ' ');
		free(tmp->content);
		tmp = tmp->prev;
	}
	find_dollar(list, env);
	// tmp = list->head;
	// while (tmp)
	// {
	// 	i = -1;
	// 	while (tmp->tab[++i])
	// 		printf("tab: %s\n", tmp->tab[i]);
	// 	tmp = tmp->prev;
	// }
}

char	what_quote(char *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
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

void	find_dollar(t_shell *list, t_env *env)
{
	t_cmd	*curr;
	int		i;
	char	*tmp;
	char	*tmp2;

	curr = list->head;
	while (curr)
	{
		i = 0;
		while (curr->tab[i])
		{
			if (curr->tab[i][0] == '$' && curr->tab[i][1] != '?' && list->single_quote == 0)
			{
				tmp2 = ft_substr(curr->tab[i], (1), ft_strlen(curr->tab[i]));
				tmp = dollar_var(list, tmp2, env);
				free(tmp2);
				free(curr->tab[i]);
				curr->tab[i] = tmp;
			}
			i++;
		}
		curr = curr->prev;
	}
}

int	return_value(t_shell *list)
{
	char	*status;

	(void)list;
	status = ft_strdup(ft_itoa(g_exit_status));
	printf("%d\n", g_exit_status);
	return (g_exit_status);	
}



int	is_redir(t_shell *list)
{
	t_cmd	*curr;
	int		i;

	curr = list->head;
	while (curr)
	{
		i = 0;
		while (curr->tab[i])
		{
			if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>'
				&& curr->tab[i] != NULL)
			{
				curr->redir_status = TRUE;
				delete_chev(curr, i);
				simple_output(curr, i);
			}
			else if (curr->tab[i][0] == '>' && curr->tab[i][1] == '>'
				&& curr->tab[i] != NULL)
			{
				curr->redir_status = TRUE;
				delete_chev(curr, i);
				dobble_output(curr, i);
			}
			else if (curr->tab[i][0] == '<' && curr->tab[i][1] != '<'
				&& curr->tab[i] != NULL)
			{
				delete_chev(curr, i);
				simple_input(curr, i);
			}
			else if (curr->tab[i][0] == '<' && curr->tab[i][1] == '<'
				&& curr->tab[i] != NULL)
			{
				delete_chev(curr, i);
				own_heredocs(curr, i);
			}
			else
				i++;
		}
		curr = curr->prev;
	}
	return (0);
}

void	delete_chev(t_cmd *curr, int i)
{
	int		j;

	free(curr->tab[i]);
	j = i + 1;
	while (curr->tab[j])
	{
		curr->tab[i] = curr->tab[j];
		i++;
		j++;
	}
	curr->tab[i] = NULL;
}
