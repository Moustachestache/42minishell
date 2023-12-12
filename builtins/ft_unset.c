/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:26:02 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/05 15:33:21 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	validates:
//	must start with _ or alpha
//	cannot contain --
static int	ft_vars_validate(char *str, t_vars *vars)
{
	int	i;

	(void) vars;
	i = 0;
	if (str[i] && ft_isdigit(str[i]) && str[i] == '-')
		return (0);
	while (str[i])
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

int	ft_unset(char *str, t_vars *vars)
{
	if (!ft_vars_validate(str, vars))
		return (ft_perror("unset: invalid parameter name", str, 1, vars));
	else
		ft_env_unset(str, vars);
	return (0);
}
