#include "minishell.h"

int	ft_strcmp_env(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		if (s1[i + 1] == '=')
			return (0);
		i++;
	}
	return (-1);
}

int	ft_strncmp2(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((0));
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (-1);
}
