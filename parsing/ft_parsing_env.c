/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:00:31 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/07 10:52:19 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env_addnode(char *valname, char *value, t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->env[i])
		i++;
	vars->env[i] = ft_calloc(1, sizeof(t_env));
	vars->env[i]->name = ft_strdup(valname);
	vars->env[i]->value = ft_strdup(value);
}

int	ft_env_unset(char *valname, t_vars *vars)
{
	int	i;

	i = 0;
	if (ft_strncmp(valname, "PWD", -1) == 0)
	{
		free(ft_forcefetch_env("PWD", vars)->value);
		ft_forcefetch_env("PWD", vars)->value = ft_strdup("");
	}
	while (vars->env[i])
	{
		if (ft_strncmp(valname, vars->env[i]->name, -1) == 0)
		{
			vars->env[i]->isunset = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_env_destroy(t_env **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]->name);
		env[i]->name = NULL;
		free(env[i]->value);
		env[i]->value = NULL;
		free(env[i]);
		i++;
	}
	free(env);
}

static t_env	*ft_init_env_node(char *line, t_vars *vars)
{
	int		namelen;
	int		strlen;
	t_env	*node;

	(void) vars;
	namelen = 0;
	while (line[namelen] && line[namelen] != '=')
		namelen++;
	namelen++;
	strlen = ft_strlen(line);
	node = ft_calloc(1, sizeof(t_env));
	node->value = ft_calloc(strlen - namelen + 1, sizeof(char));
	node->name = ft_calloc(namelen + 1, sizeof(char));
	while (--strlen - namelen >= 0)
		node->value[strlen - namelen] = line[strlen];
	while (--namelen > 0)
		node->name[namelen - 1] = line[namelen - 1];
	return (node);
}

//	man 3 limits.h
//	{ARG_MAX}
//	Maximum length of argument to the exec functions including environment data.
//	Minimum Acceptable Value: {_POSIX_ARG_MAX}
//	"getconf ARG_MAX" = 2 097 152 // ARG_MAX >> 10 = 2048
//	note: dsl timothy
//	newenv = ft_calloc((ARG_MAX >> 10) + 1, sizeof(t_env*));
//	newenv = ft_calloc(sysconf(_SC_ARG_MAX) >> 10, sizeof(t_env*));
//	final: _POSIX_ARG_MAX defined in limits. ARG_MAX not always
t_env	**ft_init_env(char **env, t_vars *vars)
{
	int		i;
	t_env	**newenv;

	(void) vars;
	newenv = ft_calloc(_POSIX_ARG_MAX, sizeof(t_env *));
	i = 0;
	while (env[i])
	{
		newenv[i] = ft_init_env_node(env[i], vars);
		i++;
	}
	return (newenv);
}
