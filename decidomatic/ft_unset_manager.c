/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:25:41 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/09 18:16:33 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset_manager(t_command *command, t_vars *vars)
{
	int		i;
	int		retval;
	char	**args;

	retval = 0;
	i = 1;
	args = command->args;
	while (args[i])
	{
		retval += ft_unset(args[i], vars);
		i++;
	}
	return (retval);
}
