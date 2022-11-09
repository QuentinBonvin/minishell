#include "minishell.h"

t_shell	*check_line(char *line, t_shell *list, t_env *env)
{
	list->double_quote = 0;
	list->single_quote = 0;
	ft_split2(line, '|', list);
	//printf_cmd(list);
	list_to_array(list, line, env);
	return (list);
}
