#include "minishell.h"

void	ft_split2(char const *line, char c, t_shell *list)
{
	//FILE* myFile = fopen("demo.txt", "w+");
	size_t	i;
	int		index;

	i = 0;
	index = -1;
	while (i <= ft_strlen(line))
	{
		if (line[i] == '\"')
		{
			i++;
			while (line[i] != '\0' && line[i] != '"')
				i++;
		}
		else if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\0' && line[i] != '\'')
				i++;
		}		
		if (line[i] != c && index < 0)
			index = i;
		else if ((line[i] == c || i == ft_strlen(line)) && index >= 0)
		{
			if ((line[0] == '"' || line[0] == SIMPLE_QUOTE)
				&& list->tail == NULL)
				index = 0;
			list->token = ft_substr(line, index, (i - index));
			//fprintf(myFile, "address of list->token\n%p\n", list->token);
			if (list->tail == NULL)
				start_stack(&list->head, &list->tail, list->token);
			else
				insert_beginning(&list->tail, list->token);
			index = -1;
		}
		i++;
	}
}

// void	ft_split2_to_long(const char *line, size_t i)
// {
// 	if (line[i] == '\"')
// 	{
// 		i++;
// 		while (line[i] != '\0' && line[i] != '"')
// 			i++;
// 	}
// 	else if (line[i] == '\'')
// 	{
// 		i++;
// 		while (line[i] != '\0' && line[i] != '\'')
// 			i++;
// 	}
// }