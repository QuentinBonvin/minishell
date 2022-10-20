#include "minishell.h"

int	check_error(char *line)
{
	if (pipe_at_start_or_end(line) == -1)
		return (-1);
	if (only_one_simple_or_dobble_quote(line) == -1)
		return (-1);
	if (is_dobble_pipe(line) == -1)
		return (-1);
	if (space_after_pipe(line) == -1)
		return (-1);
	if (quote_have_no_pair(line) == -1)
		return (-1);
	if (check_dobble_pipe_before_quote(line) == -1)
		return (-1);
	if (last_check_dobble_pipe(line) == -1)
		return (-1);
	return (0);
}