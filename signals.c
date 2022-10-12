#include "minishell.h"

void	handle_signal(struct termios *saved)
{
	hide_keystrokes(saved);
	signal(SIGINT, ctrl_c_signal);

}




void	ctrl_c_signal(int signum)
{
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();

	(void)signum;
}

void hide_keystrokes(struct termios *saved) 
{
	struct termios	attr;

    tcgetattr(STDIN_FILENO, saved);
    tcgetattr(STDIN_FILENO, &attr);
    attr.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}