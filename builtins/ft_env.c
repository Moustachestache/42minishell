/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:15:48 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/10 12:09:10 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(char **data, t_vars *vars)
{
	int	printed;
	int	i;

	(void) **data;
	printed = 0;
	i = 0;
	while (vars->env[i])
	{
		if (vars->env[i]->isunset == 0)
			printed += printf("%s=%s\n", vars->env[i]->name, \
			vars->env[i]->value);
		i++;
	}
	return (printed);
}
