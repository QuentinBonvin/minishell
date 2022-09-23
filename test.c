/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:21:26 by nnemeth           #+#    #+#             */
/*   Updated: 2022/09/23 17:26:01 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

#define TOKEN_DELIM " "

void	*ft_memset(void *b, unsigned char c, int len);

char	*ft_split_line(char *str, const char *delim) /* this should be the replica of strtok */
{
	static char *buff;
	static int	pos;
	static char *token;
	int i;
    buff = 0;
    token = 0;
	// buff = malloc(sizeof(char) * strlen(str));
	// printf("test: %s\n", str);
	pos = 0;
	if (str)
	{	
		pos = 0;
		buff = str;
		token = malloc(sizeof(char *)* strlen(buff) + 1);
		ft_memset(token, 0, strlen(buff) + 1);
	}
	// if (!str)
	// {
	// 	token = NULL;
	// }
	i = 0;
	if (!buff)
		return (0);
	// if (pos >= strlen(buff) + 1)
	// 	return (0);
	while (pos < strlen(str + 1))
	{
		if (buff[pos] == *delim)
		{
			pos++;
			return (token);
		}
		token[i] = buff[pos];
		// printf("%d\n", buff[pos]);
		i++;
		pos++;
	}
	// printf("%s\n", buff);
	return (token);
}


void	*ft_memset(void *b, unsigned char c, int len)
{
	int		i;
	char	*string;

	i = 0;
	string = b;
	while (i < len)
	{
		string[i] = c;
		i++;
	}
	b = string;
	return (b);
}

int main()
{
    char *buf = "hello world whats up";
    char *token = ft_split_line(buf, TOKEN_DELIM);
	// printf("%s\n", token);
    while (token != NULL)
    {
		printf("%s\n", token);
        token = ft_split_line(NULL, TOKEN_DELIM);
    }
    return 0;
}

// static char	ft_count(const char *str, char c)
// {
// 	int	flag;
// 	int	count;

// 	flag = 0;
// 	count = 0;
// 	if (!str)
// 		return (0);
// 	while (*str)
// 	{
// 		if (*str != c && flag == 0)
// 		{
// 			flag = 1;
// 			count++;
// 		}
// 		else if (*str == c)
// 			flag = 0;
// 		str++;
// 	}
// 	return (count);
// }

// static char	*ft_cutoff(const char *str, int start, int end)
// {
// 	int		i;
// 	char	*new;

// 	i = 0;
// 	new = malloc((end - start + 1) * sizeof(char));
// 	if (!new)
// 		return (0);
// 	while (start < end)
// 		new[i++] = str[start++];
// 	new[i] = '\0';
// 	return (new);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	**tmp;
// 	int		start;

// 	if (!s)
// 		return (0);
// 	tmp = malloc((ft_count(s, c) + 1) * sizeof(char *));
// 	if (!tmp)
// 		return (0);
// 	i = -1;
// 	j = 0;
// 	start = -1;
// 	while (++i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && start < 0)
// 			start = i;
// 		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && start >= 0)
// 		{
// 			tmp[j++] = ft_cutoff(s, start, i);
// 			start = -1;
// 		}
// 	}	
// 	tmp[j] = 0;
// 	return (tmp);
// }