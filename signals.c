#include "minishell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	sig_quit(int signum)
{
	if (signum == SIGINT)
	{
		rl_redisplay();
	}
}
