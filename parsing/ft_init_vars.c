/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:29:46 by tremy             #+#    #+#             */
/*   Updated: 2023/12/07 19:06:04 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_vars	*ft_init_vars(char **env)
{
	t_vars	*vars;
	pid_t	pid;
	char	*pid_s;
	int		shlvl;

	vars = ft_calloc(1, sizeof(t_vars));
	vars->env = ft_init_env(env, vars);
	vars->home = ft_strdup(ft_fetch_env("HOME", vars)->value);
	shlvl = ft_atoi(ft_fetch_env("SHLVL", vars)->value);
	free(ft_fetch_env("SHLVL", vars)->value);
	ft_fetch_env("SHLVL", vars)->value = ft_itoa(shlvl + 1);
	ft_add_env("SHELLNAME", "minishell", vars);
	vars->varsfd[0] = dup(STDIN_FILENO);
	vars->varsfd[1] = dup(STDOUT_FILENO);
	pid = fork ();
	if (pid == 0)
		ft_exit(0, vars);
	pid_s = ft_itoa(pid - 1);
	ft_add_env("$", pid_s, vars);
	free(pid_s);
	pid_s = NULL;
	ft_get_prompt(vars);
	return (vars);
}
