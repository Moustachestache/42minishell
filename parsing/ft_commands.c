/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:35:54 by tremy             #+#    #+#             */
/*   Updated: 2023/12/06 17:16:44 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_clean_command(char *str)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	j = ft_strlen(str);
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i];
			ft_memmove(&str[i], &str[i + 1], ft_strlen(str) - i);
			j--;
			while (str[i] && str[i] != c)
				i++;
			if (str[i] != c)
				break ;
			ft_memmove(&str[i], &str[i + 1], ft_strlen(str) - i);
			j--;
			i--;
		}
	}
	ft_bzero(&str[j], ft_strlen(&str[j]));
	return (str);
}

size_t	ft_commands_size(char **splited_line, size_t t)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (splited_line[j] && t == 0)
	{
		if (splited_line[j][0] == '|' && splited_line[j + 1])
			i++;
		j++;
	}
	while (splited_line[i] && splited_line[i][0] != '|' && t == 1)
		i++;
	return (i);
}

void	ft_command_list(char **s_line, t_command **list, size_t len)
{
	size_t		j;
	size_t		k;
	size_t		i;
	size_t		l;

	i = -1;
	k = 0;
	while (++i < len)
	{
		j = 0;
		l = ft_commands_size(&s_line[k], 1) + 1;
		(*list)[i].args = ft_calloc(l + 1, sizeof(char *));
		while (s_line[k] && s_line[k][0] != '|')
		{
			if (!ft_is_empty(s_line[k], 39, NULL)
				&& !ft_is_empty(s_line[k], 34, NULL))
				(*list)[i].args[j] = ft_strdup(s_line[k]);
			else
				(*list)[i].args[j] = ft_strdup("");
			(*list)[i].args[j] = ft_clean_command((*list)[i].args[j]);
			j++;
			k++;
		}
		k++;
	}
}

t_command	*ft_create_commands(char **splited_line, t_vars *vars)
{
	t_command	*commands;
	size_t		len;

	len = ft_commands_size(splited_line, 0);
	vars->commands_len = len;
	commands = ft_calloc(len, sizeof(t_command));
	ft_command_list(splited_line, &commands, len);
	return (commands);
}
