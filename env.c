/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:50:05 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/19 16:07:02 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		init_env(char **envp)
{
    int	i;

	i = 0;
	t_list_env	*env;
    
    env = create_env(envp);
    while (envp[i])
	{
		i++;
		add_envp_to_env(env, envp, i);
	}
    printf_env(env);
}