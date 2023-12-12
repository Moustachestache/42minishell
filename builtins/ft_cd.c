/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:51:19 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/07 15:14:05 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_set_pwd(char *newpath, t_vars *vars)
{
	t_env	*pwd;
	t_env	*oldpwd;

	(void) newpath;
	pwd = ft_forcefetch_env("PWD", vars);
	oldpwd = ft_forcefetch_env("OLDPWD", vars);
	if (oldpwd)
	{
		free(oldpwd->value);
		if (pwd && pwd->value)
			oldpwd->value = pwd->value;
	}
	if (pwd)
	{
		pwd->value = ft_calloc(_POSIX_PATH_MAX, sizeof (char));
		getcwd(pwd->value, _POSIX_PATH_MAX);
	}
}

static char	*ft_find_path(char *dir, t_vars *vars)
{
	char	*newpath;
	char	**env_split;
	char	*temp;
	int		i;

	i = 0;
	newpath = NULL;
	env_split = ft_split(ft_fetch_env("PATH", vars)->value, ':');
	while (env_split[i])
	{
		temp = ft_strjoin(env_split[i], dir);
		if (chdir(temp) == 0)
		{
			newpath = temp;
			break ;
		}
		else
			free(temp);
		i++;
	}
	ft_free_split(env_split);
	return (newpath);
}

static int	ft_validate_cdpath(char *path)
{
	int	i;

	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		if (ft_isposix_char(path[i]) || path[i] == '/')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_cd(char *dir, t_vars *vars)
{
	char	*newpath;
	t_env	*homedir;

	newpath = NULL;
	homedir = ft_fetch_env("HOME", vars);
	if (!dir || dir[0] == '\0')
	{
		if (!homedir)
			return (ft_perror("cd", "HOME not set", 1, vars));
		newpath = ft_strdup(homedir->value);
	}
	else if (dir[0] == '~')
		newpath = ft_tilde(dir, vars);
	else if (dir[0] == '/')
		newpath = ft_find_path(dir, vars);
	else
		newpath = ft_strdup(dir);
	if (ft_validate_cdpath(newpath) == 1 && chdir(newpath) == 0)
		ft_set_pwd(newpath, vars);
	else
		return (ft_perror("cannot find directory", dir, 1, vars));
	free(newpath);
	newpath = NULL;
	return (0);
}
