#include "minishell.h"

int	builtin(char *line, t_shell *list)
{
	t_cmd *current;
	char *aux;
	int	i;

	(void)line;
	current = list->head;
	i = 0;
	if (list == NULL)
		return (1);
	if (ft_strcmp(&current->content[i], "pwd") == 0)
	{
		aux = getcwd(NULL,0);
		printf("%s\n", aux);
	}
	if (ft_strcmp(&current->content[i], "cd") == 0)
	{
		printf("cd works\n");
	}
	if (ft_strcmp(&current->content[i], "echo") == 0)
		printf("echo works\n");
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		i++;
	if (*s1== *s2)
		return (0);
	else
		return (-1);
}
