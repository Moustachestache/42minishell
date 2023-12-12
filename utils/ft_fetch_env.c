/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:11:40 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/30 18:30:35 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	finds $varname environment variable
//	if variable isnt set, return NULL
//	returns its pointer
t_env	*ft_fetch_env(char *varname, t_vars *vars)
{
	int	i;

	if (ft_strncmp(varname, "$", -1) == 0)
		return (ft_forcefetch_env(varname, vars));
	i = 0;
	while (vars->env[i])
	{
		if (ft_strncmp(varname, vars->env[i]->name, -1) == 0)
		{
			if (vars->env[i]->isunset == 0)
				return (vars->env[i]);
		}
		i++;
	}
	return (NULL);
}

//	don't use me
//	use the one above. only returns if variable exists.
t_env	*ft_forcefetch_env(char *varname, t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->env[i])
	{
		if (ft_strncmp(varname, vars->env[i]->name, -1) == 0)
			return (vars->env[i]);
		i++;
	}
	return (NULL);
}
