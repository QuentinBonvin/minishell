#include "minishell.h"

int	call_cd(char *aux, char *path)
{
	aux = getcwd(NULL, 0);
	chdir(path);
	printf("change dir: %s\n", aux);
	return (0);
}