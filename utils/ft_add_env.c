/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:52:01 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/16 14:53:09 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_add_env(char *name, char *value, t_vars *vars)
{
	int	i;

	i = 0;
	if (!name || name[0] == '\0')
		return (1);
	if (!value)
		value = ft_strdup("");
	while (vars->env[i])
		i++;
	vars->env[i] = ft_calloc(1, sizeof(t_env));
	if (!vars->env[i])
		return (1);
	vars->env[i]->name = ft_strdup(name);
	vars->env[i]->value = ft_strdup(value);
	if (!ft_strncmp(name, "?", -1) || !ft_strncmp(name, "$", -1))
		vars->env[i]->isunset = 1;
	return (0);
}
