#include "minishell.h"

int	ft_error(char **arg)
{
	printf("%s", arg[0]);
	printf(": ");
	printf("%s", arg[1]);
	printf(": ");
	printf("%s", strerror(errno));
	printf(" ");
	printf("\n");
	g_exit_status = 1;
	return (1);
}
