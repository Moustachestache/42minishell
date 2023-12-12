/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:26:35 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/01 12:51:50 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd_manager(t_command *command, t_vars *vars)
{
	int		retval;
	char	**args;

	retval = 0;
	args = command->args;
	(void) vars;
	if (!args)
		return (1);
	if (args[0] && !args[1])
		retval = ft_cd(args[1], vars);
	else if (args[1] && args[2])
		return (ft_perror("cd", "too many arguments", 1, vars));
	else
		retval = ft_cd(args[1], vars);
	if (retval == 0)
		ft_get_prompt(vars);
	return (retval);
}
