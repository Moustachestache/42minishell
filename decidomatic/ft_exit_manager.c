/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:16 by tremy             #+#    #+#             */
/*   Updated: 2023/12/06 10:11:49 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit_manager(t_command *command, t_vars *vars)
{
	char	**args;
	int		out_value;
	int		retval;

	out_value = 0;
	args = command->args;
	if (args[1])
		out_value = ft_atoi(args[1]);
	printf("exit\n");
	retval = ft_exit(out_value, vars);
	return (retval);
}
