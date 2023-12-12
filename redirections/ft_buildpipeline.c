/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildpipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:48:38 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/06 12:27:49 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_fetchincont(size_t i, char **cmd, t_vars *vars)
{
	int	retval;

	retval = STDIN_FILENO;
	if (cmd[i + 1])
	{
		retval = open(cmd[i + 1], O_RDONLY);
		if (retval < 0)
			retval = ft_perror("open: invalid file", cmd[i + 1], -1, vars);
	}
	else
		ft_perror("invalid file", NULL, 1, vars);
	return (retval);
}

static int	ft_fetchinfile(char **cmd, t_vars *vars)
{
	size_t	i;
	int		retval;

	retval = STDIN_FILENO;
	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], "<<", -1) == 0)
		{
			if (cmd[i + 1])
				return (ft_heredoc(cmd[i + 1], vars));
			else
				ft_perror("heredoc", "invalid file delimiter", 1, vars);
		}
		else if (ft_strncmp(cmd[i], "<", -1) == 0)
			retval = ft_fetchincont(i, cmd, vars);
		i++;
	}
	return (retval);
}

//	returns open fd for outfile
//	if nothing adds to stdout

static int	ft_fetchoutcont(size_t i, char **cmd, t_vars *vars)
{
	int	retval;

	retval = STDOUT_FILENO;
	if (cmd[i + 1])
	{
		retval = open(cmd[i + 1], O_RDWR | O_APPEND | O_CREAT, 0664);
		if (retval < 0)
			retval = ft_perror("open", NULL, STDOUT_FILENO, vars);
	}
	return (retval);
}

static int	ft_fetchoutfile(char **cmd, t_vars *vars)
{
	size_t	i;
	int		retval;

	(void) vars;
	retval = STDOUT_FILENO;
	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], ">", -1) == 0)
		{
			if (cmd[i + 1])
			{
				retval = open(cmd[i + 1], O_RDWR | O_TRUNC | O_CREAT, 0664);
				if (retval < 0)
					retval = ft_perror("open", NULL, STDOUT_FILENO, vars);
			}
		}
		if (ft_strncmp(cmd[i], ">>", -1) == 0)
			retval = ft_fetchoutcont(i, cmd, vars);
		i++;
	}
	return (retval);
}

//	outfile	default == stdout;
//	open and create
//	infile	default == stdin;
t_pipeline	*ft_buildpipeline(t_vars *vars)
{
	size_t		i;
	t_pipeline	*pipeline;
	t_command	*commands;

	commands = vars->commands;
	pipeline = ft_calloc(vars->commands_len, sizeof(t_pipeline));
	i = 0;
	while (i < vars->commands_len)
	{
		pipeline[i].infile = ft_fetchinfile(commands[i].args, vars);
		pipeline[i].outfile = ft_fetchoutfile(commands[i].args, vars);
		i++;
	}
	return (pipeline);
}
