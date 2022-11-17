#include "minishell.h"

void	find_dollar(t_shell *list, t_env *env)
{
	t_cmd	*curr;

	curr = list->head;
	while (curr)
	{
		detect_dollar(list, curr->tab, env);
		curr = curr->prev;
	}
}

void	detect_dollar(t_shell *list, char **str, t_env *env)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (str[++i])
	{
		if ((ft_strncmp(str[i], "$", ft_strlen(str[i])) == 0)
			&& (str[i][1] != '?'))
			break ;
		else if (((str[i][0] == '$' ) && str[i][1] != '\0')
			&& list->single_quote == 0 && str[i][1] != '$' && str[i][1] != '?')
		{				
			tmp2 = ft_substr(str[i], 1, ft_strlen(str[i]));
			tmp = dollar_var(list, tmp2, env);
			free(tmp2);
			free(str[i]);
			str[i] = tmp;
		}
		else if (ft_strncmp2(str[i], "$?", 2) == 0)
			return_value(list, str);
	}
}
