/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unredir_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:28:34 by tremy             #+#    #+#             */
/*   Updated: 2023/12/06 12:37:47 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_new_cmd_len(char **cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (ft_strncmp(">", cmd[i], -1) != 0
			&& ft_strncmp(">>", cmd[i], -1) != 0
			&& ft_strncmp("<", cmd[i], -1) != 0
			&& ft_strncmp("<<", cmd[i], -1) != 0)
			j++;
		i++;
	}
	return (j);
}

char	**ft_unredir_command(char **cmd)
{
	char	**new_cmd;
	int		i;
	int		j;

	new_cmd = ft_calloc(ft_new_cmd_len(cmd) + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (ft_strncmp(">", cmd[i], -1) == 0
			|| ft_strncmp(">>", cmd[i], -1) == 0
			|| ft_strncmp("<", cmd[i], -1) == 0
			|| ft_strncmp("<<", cmd[i], -1) == 0)
			i = i + 2;
		else if (cmd[i])
		{
			new_cmd[j] = ft_strdup(cmd[i]);
			i++;
			j++;
		}
	}
	ft_free_split(cmd);
	return (new_cmd);
}
