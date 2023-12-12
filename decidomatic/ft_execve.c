/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:15:11 by tremy             #+#    #+#             */
/*   Updated: 2023/12/08 16:25:19 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_get_env(t_vars *vars)
{
	int		i;
	char	*temp;

	i = 0;
	while (vars->env[i])
		i++;
	vars->env_tab = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (vars->env[i])
	{
		temp = ft_strjoin(vars->env[i]->name, "=");
		vars->env_tab[i] = ft_strjoin(temp, vars->env[i]->value);
		i++;
		free(temp);
		temp = NULL;
	}
	return (vars->env_tab);
}

char	**ft_get_paths(t_vars *vars)
{
	char	*buf;
	char	*current_dir;
	char	*temp_paths;
	char	**paths;

	buf = ft_calloc(PATH_MAX, sizeof(char));
	getcwd(buf, PATH_MAX);
	current_dir = ft_strjoin(":", buf);
	temp_paths = ft_strjoin(ft_fetch_env("PATH", vars)->value, current_dir);
	paths = ft_split(temp_paths, ':');
	free(buf);
	free(current_dir);
	free(temp_paths);
	buf = NULL;
	current_dir = NULL;
	temp_paths = NULL;
	return (paths);
}

char	*ft_get_path(t_vars *vars, t_command *command, int i)
{
	char	**paths;
	char	*temp;
	char	*path;

	paths = ft_get_paths(vars);
	path = NULL;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, command->args[0]);
		free(temp);
		temp = NULL;
		if (!access(path, F_OK))
			break ;
		free(path);
		path = NULL;
	}
	ft_free_split(paths);
	if (path)
		return (path);
	else
		return (NULL);
}

int	ft_child(char *path, t_command *command, t_vars *vars)
{
	int	value;

	//value = execve(command->args[0], command->args, vars->env_tab);
	//if (value == -1)
		value = execve(path, command->args, vars->env_tab);
	if (value == -1)
	{
		ft_perror("command not found", command->args[0], 127, vars);
		return (ft_exit(127, vars));
	}
	return (value);
}

int	ft_execve(t_vars *vars, t_command *command)
{
	pid_t	child;
	int		value;
	char	*path;

	child = fork();
	value = 0;
	path = ft_get_path(vars, command, -1);
	vars->env_tab = ft_get_env(vars);
	if (child == 0)
		ft_child(path, command, vars);
	waitpid(child, &value, WUNTRACED | WCONTINUED);
	value = value >> 8;
	free(path);
	path = NULL;
	return (value);
}
