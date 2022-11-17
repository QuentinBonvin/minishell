#include "minishell.h"

static void	delete_space(t_shell *list);

void	list_to_array(t_shell *list, t_env *env)
{
	t_cmd	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = list->head;
	while (tmp != NULL)
	{
		//tmp->tab = (char**) malloc(sizeof(char*));
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[0] == DOBBLE_QUOTE)
				list->double_quote = 1;
			if (tmp->content[0] == SIMPLE_QUOTE)
				list->single_quote = 1;
			if (tmp->content[i] == ' ')
			{
				//tmp->tab[0] = ft_substr(tmp->content, 0, i);
				//printf("adress tmp->tab[0] = %p\n", tmp->tab[0]);
				j = i;
				break ;
			}
			i++;
		}

		while (tmp->content[j])
		{
			if (what_quote(&tmp->content[j]) == 1)
			{
				list->single_quote = 1;
				tmp->tab = ft_split(tmp->content, '\'');
				break ;
			}
			else if (what_quote(&tmp->content[j]) == 2)
			{
				list->double_quote = 1;
				tmp->tab = ft_split(tmp->content, '\"');
				break ;
			}
			else if (what_quote(&tmp->content[j]) == 3)
			{
				// list->double_quote = 1;
				tmp->tab = ft_split(tmp->content, ' ');
				//printf("adress tmp->tab[0] after split = %p\n", tmp->tab[0]);
				break ;
			}
			j++;
		}
		free(tmp->content);
		tmp = tmp->prev;
	}
	//(void)env;
	find_dollar(list, env);
	// tmp = list->head;
	while (tmp)
	{
		i = -1;
		while (tmp->tab[++i])
			printf("tab: %s\n", tmp->tab[i]);
		tmp = tmp->prev;
	}
	delete_space(list);
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
			if (curr->tab[i][0] == '$' && curr->tab[i][1] != '?'
				&& list->single_quote == 0)
			{
				tmp2 = ft_substr(curr->tab[i], (1), ft_strlen(curr->tab[i]));
				tmp = dollar_var(list, tmp2, env);
				free(tmp2);
				free(curr->tab[i]);
				curr->tab[i] = tmp;
			}
			if (ft_strcmp(curr->tab[i], "$?") == 0)
				return_value(list, curr->tab);
			else
				i++;
		}
		curr = curr->prev;
	}
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
			command[i] = ft_itoa(g_exit_status);
		}
		i++;
	}
	return (g_exit_status);
}

static void	delete_space(t_shell *list)
{
	t_cmd	*tmp;

	//char	*tmp_trim;
	int		i;
	int		y;

	y = 0;
	i = 0;

	tmp = list->head;
	while (tmp)
	{
		i = 0;
		while (tmp->tab[i])
		{
			tmp->tab[i] = ft_strtrim(tmp->tab[i], " ");
			i++;
		}
		tmp = tmp->prev;
	}
	

}
