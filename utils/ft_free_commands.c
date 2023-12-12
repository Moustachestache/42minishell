/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:19:00 by tremy             #+#    #+#             */
/*   Updated: 2023/12/08 11:33:38 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_commands(t_vars *vars, t_command **commands, size_t l)
{
	size_t	i;

	(void) l;
	i = 0;
	while (i < l)
	{
		ft_free_split((*commands)[i].args);
		i++;
	}
	free(*commands);
	vars->commands = NULL;
}
