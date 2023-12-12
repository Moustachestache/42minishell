/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decidomatic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:31:50 by tremy             #+#    #+#             */
/*   Updated: 2023/12/08 11:33:10 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_prefork_function(t_command *command, t_vars *vars)
{
	int		retval;
	char	**args;

	retval = 0;
	command->args = ft_unredir_command(command->args);
	args = command->args;
	if (!ft_strncmp(args[0], "exit", -1))
		retval = ft_exit_manager(command, vars);
	else if (!ft_strncmp(args[0], "unset", -1))
		retval = ft_unset_manager(command, vars);
	else if (!ft_strncmp(args[0], "export", -1))
		retval = ft_export_manager(command, vars);
	else if (!ft_strncmp(args[0], "cd", -1))
		retval = ft_cd_manager(command, vars);
	return (retval);
}

//	ret 1	if exit, unset or cd
//	ret 0	rest
static int	ft_isunforkable(t_command *command, t_vars *vars)
{
	char	**args;

	(void) vars;
	args = command->args;
	if (args[0]
		&& ((!ft_strncmp(args[0], "exit", -1))
			|| ((!ft_strncmp(args[0], "export", -1)) && args[1])
			|| (!ft_strncmp(args[0], "unset", -1))
			|| (!ft_strncmp(args[0], "cd", -1))))
		return (1);
	return (0);
}

int	ft_find_function(t_command *command, t_vars *vars)
{
	int		retval;
	char	**args;

	retval = 0;
	command->args = ft_unredir_command(command->args);
	args = command->args;
	if (!ft_strncmp(args[0], "echo", -1))
		retval = ft_echo_manager(command, vars);
	else if (!ft_strncmp(args[0], "export", -1))
		retval = ft_export_manager(command, vars);
	else if (!ft_strncmp(args[0], "env", -1))
		retval = ft_env_manager(command, vars);
	else
		retval = ft_execve(vars, command);
	return (retval);
}

//	ft_buildpipeline
//	in /redirections/
int	ft_decidomatic(t_vars *vars)
{
	int			retval;
	int			forkid;
	int			pipefd[2];
	size_t		i;
	t_command	*commands;

	retval = 0;
	vars->pipeline = ft_buildpipeline(vars);
	commands = vars->commands;
	i = 0;
	while (i < vars->commands_len)
	{
		if (ft_isunforkable(&commands[i], vars))
			retval = ft_prefork_function(&commands[i], vars);
		else
		{
			if (vars->commands_len != 1)
				if (pipe(pipefd) == -1)
					return (0);
			forkid = fork();
			retval = ft_fork(forkid, i, pipefd, vars);
		}
		i++;
	}
	return (retval);
}
