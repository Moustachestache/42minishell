/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:44:30 by tremy             #+#    #+#             */
/*   Updated: 2023/12/08 11:25:31 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_fork_child(size_t i, int *fd, t_vars *vars)
{
	ft_mootsignal();
	if (i + 1 != vars->commands_len)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	ft_redirections(vars->pipeline[i], vars);
	return (ft_find_function(&vars->commands[i], vars));
}

int	ft_fork(int forkid, size_t i, int *fd, t_vars *vars)
{
	int	retval;

	if (forkid == 0)
	{
		retval = ft_fork_child(i, fd, vars);
		ft_exit(retval, vars);
	}
	if (i + 1 != vars->commands_len)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	signal(SIGINT, ft_adult_sig);
	signal(SIGQUIT, ft_adult_sig);
	if (i + 1 == vars->commands_len)
		dup2(vars->varsfd[0], STDIN_FILENO);
	waitpid(forkid, &retval, WUNTRACED);
	retval = retval >> 8;
	return (retval);
}
