/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:41:53 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/08 12:56:36 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_free(t_vars *vars)
{
	t_pipeline	*pipeline;

	ft_env_destroy(vars->env);
	if (vars->env_tab)
		ft_free_split(vars->env_tab);
	pipeline = vars->pipeline;
	if (&pipeline[0])
	{
		free(pipeline);
		pipeline = NULL;
	}
	free(vars->home);
	vars->home = NULL;
	free(vars);
}

int	ft_exit(int exit_value, t_vars *vars)
{
	ft_free(vars);
	exit(exit_value);
	return (exit_value);
}
