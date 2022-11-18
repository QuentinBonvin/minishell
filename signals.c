/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:27:23 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 14:27:25 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(struct termios *saved)
{
	hide_keystrokes(saved);
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrl_c_signal(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	hide_keystrokes(struct termios *saved)
{	
	struct termios	attr;

	tcgetattr(STDIN_FILENO, &attr);
	tcgetattr(STDIN_FILENO, saved);
	attr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}

void	handle_sigquit(int signal)
{
	if (signal == SIGINT)
	{
		write (1, "\n", 1);
	}
	if (signal == SIGQUIT)
	{
		printf("Quit: 3\n");
		rl_on_new_line();
	}
}
