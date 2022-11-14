#include "minishell.h"

void	sort_and_swap(char **env_array, int l)
{
	int		swapped;
	char	*tmp;
	int		i;

	swapped = 0;
	while (env_array && swapped == 0)
	{
		swapped = 1;
		i = -1;
		while (++i < (l - 1))
		{
			if (ft_compare(env_array[i], env_array[i + 1]) > 0)
			{
				tmp = env_array[i];
				env_array[i] = env_array[i + 1];
				env_array[i + 1] = tmp;
				swapped = 0;
			}
		}
		l--;
	}
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[i]) == 1)
		return (-1);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalpha(arg[i]) == 0)
			return (2);
		i++;
	}
	if (arg[i] != '=')
		return (3);
	return (1);
}
