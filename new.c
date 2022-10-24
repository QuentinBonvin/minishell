#include "minishell.h"

// int    no_quote_or_no_pipe(char *line)
// {
//     int i;
//     int    pipe;
//     int quote;

//     i = 0;
//     pipe = 0;
//     quote = 0;
//     while (line[i])
//     {
//         if (line[i] == SIMPLE_QUOTE || line[i] == DOBBLE_QUOTE)
//             quote++;
//         if (line[i] == PIPE)
//             pipe++;
//         i++;
//     }
//     if (quote == 0 && pipe == 0)
//         return (1);
//     return (0);
// }

// void    splitting_with_space(char *line, t_shell *list)
// {
//     char    **word_dup;
//     int        i;

//     i = 1;
//     word_dup = ft_split(line, ' ');
//     list->token = word_dup[0];
//     start_stack(&list->head, &list->tail, list->token);
//     while (word_dup[i])
//     {
//         list->token = word_dup[i];
//         insert_beginning(&list->tail, list->token);
//         i++;
//     }
//     printf_cmd(list);
// }