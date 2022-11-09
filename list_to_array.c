#include "minishell.h"

void	list_to_array(t_shell *list, char *line, t_env *env)
{
	t_cmd	*curr;
	t_cmd	*tmp;
	int		i;
	(void)line;

	i = 0;
	curr = list->head;
	tmp = curr;
	while (tmp != NULL)
	{
		if (what_quote(tmp->content) == 1)
		{
			list->single_quote = 1;
			tmp->tab = ft_split(tmp->content, '\'');
		}
		else if (what_quote(tmp->content) == 2)
			tmp->tab = ft_split(tmp->content, '\"');
		else if (what_quote(tmp->content) == 3)
			tmp->tab = ft_split(tmp->content, ' ');
		free(tmp->content);
		tmp = tmp->prev;
	}
	tmp = curr;
	find_dollar(list, env);
	while (tmp)
	{
		i = -1;
		while (tmp->tab[++i])
			printf("tab: %s\n", tmp->tab[i]);
		tmp = tmp->prev;
	}
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
		else
			return (3);
	}
	return (0);
}

// void	list_to_array(t_shell *list, char *line, t_env *env)
// {
// 	(void)line;
// 	t_cmd	*curr;
// 	char	*cmd;
// 	(void)env;
// 	//t_cmd	*tmp;
// 	int		i;
// 	int		j;

// 	curr = list->head;
// 	// tmp = curr;.
// 	curr->tab = malloc(sizeof(char *));
// 	while (curr != NULL)
// 	{
// 		//cmd = split_space(list, ' ');
// 		//printf("cmd after split splace = %s\n", cmd);
// 		i = 0;
// 		j = 0;
// 		while(curr->content[i])
// 		{
// 			if (curr->content[i] == ' ' || curr->content[i] == '\0')
// 			{
// 				cmd = split_space(list, ' ');
// 				curr->tab[j] = cmd;
// 				cmd = ft_substr(curr->content, ft_strlen(cmd), ft_strlen(curr->content));
// 				i = ft_strlen(cmd);
// 				j++;
// 			}
// 			// curr->tab[i] = malloc(sizeof(char *));
// 			i++;
// 		}
// 		printf("tab[0] = %s\n", curr->tab[0]);
// 		printf("tab[1] = %s\n", curr->tab[1]);
// 		printf("cmd = %s\n", cmd);
// 		curr = curr->prev;
		
		
// 	}
// 	// tmp = curr;
// 	// find_dollar(list, env);
// 	// while (tmp)
// 	// {
// 	// 	i = -1;
// 	// 	while (tmp->tab[++i])
// 	// 		printf("tab: %s\n", tmp->tab[i]);
// 	// 	tmp = tmp->prev;
// 	// }
// }

// char	*split_space(t_shell *list, int c)
// {
// 	t_cmd	*tmp;
// 	char	*ret_cmd;
// 	int		i;
// 	int		ret;
	
// 	i = 0;
// 	ret_cmd = NULL;
// 	tmp = list->head;
// 	while (tmp->content[i])
// 	{
// 		if (tmp->content[i] == c)
// 		{
// 			ret = check_if_space_beewtween_quote(tmp->content, i);
// 			if (ret == 0)
// 			{
// 				ret_cmd = ft_substr(tmp->content, 0, i);
// 				break ;
// 			}
// 			else if (ret == 1)
// 			{
// 				ret_cmd = ft_substr(tmp->content, 0, ft_strlen(tmp->content));
// 				break ;
// 			}
// 			else
// 			{
// 				ret_cmd = ft_substr(tmp->content, 0, (ret + 1));
// 				break ;
// 			}
// 		}
// 		i++;
// 	}
// 	return (ret_cmd);
	
// }

// int check_if_space_beewtween_quote(char *line, int index_space)
// {
// 	int i;

// 	i = 0;
// 	while (i < index_space)
// 	{
// 		while (line[i] != ' ')
// 		{
// 			if (line[i] == SIMPLE_QUOTE || line[i] == DOBBLE_QUOTE)
// 			{
// 				i = is_quote(line, i);
// 				if (i == (index_space - 1))
// 					return (i);
// 				else
// 					return (1);
// 				// else
// 			}
// 			i++;
// 		}
// 	}
// 	return (0);
	
// }


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
			if (curr->tab[i][0] == '$' && list->single_quote == 0)
			{
				tmp2 = ft_substr(curr->tab[i], (1), ft_strlen(curr->tab[i]));
				printf("tmp = %p\n", tmp);
				printf("curr->tab[i] = %p\n", curr->tab[i]);
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
