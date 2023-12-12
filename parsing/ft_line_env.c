/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:26 by tremy             #+#    #+#             */
/*   Updated: 2023/12/08 12:41:52 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_dolnum(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == 39)
		{
			i++;
			while (str[i] != 39)
				i++;
			j += 2;
		}
		if (str[i] == c || str[i] == 34)
			j += 2;
		i++;
	}
	return (j);
}

void	ft_noquote_cpy(char *str, char ***tab, int **values, t_vars *vars)
{
	char	**tabb;
	char	*var_name;
	int		*v;

	v = *values;
	tabb = *tab;
	if (v[2] != v[0])
		tabb[++v[1]] = ft_substr(str, v[2], v[0] - v[2]);
	v[2] = ++v[0];
	while (str[v[0]] && (ft_isalnum(str[v[0]]) || str[v[0]] == '_' )
		&& (ft_isalpha(str[v[2]]) || str[v[2]] == '_'))
		v[0]++;
	if (v[2] == v[0] && (str[v[0]] == '$' || str[v[0]] == '?'
			|| !(ft_isalpha(str[v[2]]) || str[v[2]] == '_')))
		v[0]++;
	var_name = ft_substr(str, v[2], v[0] - v[2]);
	if (var_name[0] == '?' && !var_name[1])
		tabb[++v[1]] = ft_itoa(vars->retval);
	else if (ft_fetch_env(var_name, vars))
		tabb[++v[1]] = ft_strdup(ft_fetch_env(var_name, vars)->value);
	else
		tabb[++v[1]] = ft_strdup("");
	free(var_name);
	var_name = NULL;
	v[2] = v[0]--;
}

void	ft_quote_cpy(char *str, char ***tab, int **values, t_vars *vars)
{
	char	**tabb;
	int		*v;

	v = *values;
	tabb = *tab;
	v[0]++;
	if (str[v[0] - 1] && str[v[0] - 1] == 34)
	{
		while (str[v[0]] != 34)
		{
			if (str[v[0]] == '$')
				ft_noquote_cpy(str, &tabb, &v, vars);
			v[0]++;
		}
	}
	else if (str[v[0] - 1] && str[v[0] - 1] == 39)
	{
		while (str[v[0]] != 39)
			v[0]++;
	}
	if (v[0] != v[2])
	{
		tabb[++v[1]] = ft_substr(str, v[2], v[0] - v[2] + 1);
		v[2] = v[0] + 1;
	}
}

char	**ft_browse(char *str, t_vars *vars)
{
	int		*values;
	char	**tab;

	values = ft_calloc(3, sizeof(int));
	values[0] = 0;
	values[1] = -1;
	values[2] = 0;
	tab = ft_calloc(ft_dolnum(str, '$') + 1, sizeof(char *));
	ft_retvalsig(vars);
	while (str[values[0]])
	{
		if (str[values[0]] == '$')
			ft_noquote_cpy(str, &tab, &values, vars);
		if (str[values[0]] == 34 || str[values[0]] == 39)
			ft_quote_cpy(str, &tab, &values, vars);
		values[0]++;
	}
	if (values[0] != values[2])
		tab[++values[1]] = ft_substr(str, values[2], values[0]);
	free(str);
	free(values);
	str = NULL;
	return (tab);
}

char	**ft_line_env(char **line, t_vars *vars)
{
	int	i;

	i = 0;
	while (line[i])
	{
		line[i] = ft_ultimate_join(ft_browse(line[i], vars));
		i++;
	}
	return (line);
}
