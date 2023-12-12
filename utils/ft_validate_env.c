/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:13:02 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/08 16:52:44 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_validate_env(char *env, size_t len, t_vars *vars)
{
	size_t	i;

	i = 0;
	if (!env || len == 0)
		return (0);
	if (env[0] && !ft_isalpha(env[0]) && env[0] != '_')
		return (0);
	i++;
	while (env[i] && i < len)
	{
		if (!ft_isalnum(env[i]) && env[i] != '_')
			return (0);
		i++;
	}
	(void)vars;
	return (1);
}
