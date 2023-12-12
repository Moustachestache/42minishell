/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:54:18 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/09 16:24:00 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char **data, char *arg, t_vars *vars)
{
	int	i;

	(void) vars;
	i = 0;
	while (data[i])
	{
		printf("%s", data[i]);
		if (data[i + 1])
			printf(" ");
		i++;
	}
	if (!arg)
		printf("%c", '\n');
	return (0);
}
