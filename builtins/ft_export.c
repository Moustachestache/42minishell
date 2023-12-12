/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:36:45 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/07 15:13:38 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_export_swap(t_env *source, t_env *target)
{
	t_env	swap;

	swap = *source;
	*source = *target;
	*target = swap;
}

static void	ft_print_list(t_env **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (list[i]->isunset == 0)
			printf("export -x %s=\"%s\"\n", list[i]->name, list[i]->value);
		i++;
	}
}

static int	ft_export_list(t_vars *vars)
{
	int		i;
	int		j;
	t_env	**tempenv;

	i = -1;
	j = 1;
	tempenv = ft_calloc(_POSIX_ARG_MAX, sizeof (t_env *));
	while (vars->env[++i])
		tempenv[i] = vars->env[i];
	i = -1;
	while (tempenv[++i])
	{
		while (tempenv[++j])
		{
			if (ft_strncmp(tempenv[j - 1]->name, tempenv[j]->name, -1) > 0)
				ft_export_swap(tempenv[j - 1], tempenv[j]);
		}
		j = 1;
	}
	ft_print_list(tempenv);
	free(tempenv);
	return (0);
}

static int	ft_export_write(t_env *temp_env, char **temp_cmd, t_vars *vars)
{
	int	retval;

	retval = 0;
	if (!ft_validate_env(temp_cmd[0], -1, vars))
		return (ft_perror("export: wrong identifier", temp_cmd[0], 1, vars));
	else if (temp_env && temp_cmd)
	{
		if (temp_env->value)
			free(temp_env->value);
		if (temp_cmd[1])
			temp_env->value = ft_strdup(temp_cmd[1]);
		else
			temp_env->value = ft_strdup("");
		temp_env->isunset = 0;
	}
	else if (temp_cmd)
		ft_add_env(temp_cmd[0], temp_cmd[1], vars);
	return (retval);
}

int	ft_export(char **cmd, t_vars *vars)
{
	int		i;
	int		ret_val;
	t_env	*temp_env;
	char	**temp_cmd;

	if (!cmd[1])
		return (ft_export_list(vars));
	i = 1;
	ret_val = 0;
	while (cmd[i])
	{
		temp_cmd = ft_split(cmd[i], '=');
		temp_env = ft_forcefetch_env(temp_cmd[0], vars);
		ret_val = ft_export_write(temp_env, temp_cmd, vars);
		ft_free_split(temp_cmd);
		i++;
	}
	return (ret_val);
}
