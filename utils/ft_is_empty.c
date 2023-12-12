/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:26 by tremy             #+#    #+#             */
/*   Updated: 2023/12/08 16:29:41 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_empty(char *str, char c, t_vars *vars)
{
	int	i;

	(void) vars;
	i = 0;
	if (!str)
	{
		if (vars)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		return (1);
	}
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
