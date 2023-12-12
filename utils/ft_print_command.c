/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:14:06 by tremy             #+#    #+#             */
/*   Updated: 2023/10/31 15:35:47 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_command(t_vars *vars)
{
	size_t		i;
	size_t		j;
	t_command	*command;

	i = 0;
	j = 0;
	while (i < vars->commands_len)
	{
		j = 0;
		command = &vars->commands[i];
		while (command->args[j])
		{
			printf("argument n°%ld : %s\n", i, command->args[j]);
			j++;
		}
		i++;
	}
}

void	ft_print_split(char **s_line)
{
	size_t		i;

	i = 0;
	while (s_line[i])
	{
		printf("argument n°%ld : %s\n", i, s_line[i]);
		i++;
	}
}
