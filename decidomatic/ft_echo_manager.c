/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:05:14 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/30 16:26:07 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo_manager(t_command *command, t_vars *vars)
{
	char	**args;
	char	*arg;

	args = command->args;
	if (!args[1])
		return (ft_echo(&args[1], 0, vars));
	if (args[1] && ft_strncmp(args[1], "-n", 2) != 0)
		arg = NULL;
	else
	{
		arg = args[2];
		args++;
	}
	return (ft_echo(&args[1], arg, vars));
}
