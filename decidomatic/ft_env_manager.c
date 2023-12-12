/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:49:52 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/06 12:11:40 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env_manager(t_command *command, t_vars *vars)
{
	(void) vars;
	if (command->args[1])
		return (ft_perror("env: no such file or directory", \
		command->args[1], 1, vars));
	return (ft_env(command->args, vars));
}
