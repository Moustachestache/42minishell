/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:00:09 by tremy             #+#    #+#             */
/*   Updated: 2023/12/06 16:01:08 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*ft_parsing(char *line, t_vars *vars)
{
	char		**splited_line;
	t_command	*commands;

	splited_line = ft_ultimate_split(line, 32, vars);
	if (!splited_line)
		return (0);
	splited_line = ft_line_env(splited_line, vars);
	commands = ft_create_commands(splited_line, vars);
	ft_free_split(splited_line);
	return (commands);
}
