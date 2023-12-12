/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:40:08 by tremy             #+#    #+#             */
/*   Updated: 2023/12/07 10:49:18 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

const char	*ft_redir_space(const char *s, int i, int j)
{
	char	*new_str;

	while (s[++i])
	{
		if (s[i] == '<' || s[i] == '>')
			j++;
		if ((s[i + 1] == '<' && s[i] == '<')
			|| (s[i + 1] == '>' && s[i] == '<'))
			i++;
	}
	new_str = ft_calloc(ft_strlen(s) + j * 2 + 1, sizeof(char));
	i = 0;
	j = -1;
	while (s[++j])
	{
		if ((s[j] == 62 || s[j] == 60) && (s[j - 1] != 60 && s[j - 1] != 62))
			new_str[i++] = ' ';
		if (j != 0 && (s[j] != 60 && s[j] != 62)
			&& (s[j - 1] == 62 || s[j - 1] == 60))
			new_str[i++] = ' ';
		new_str[i++] = s[j];
	}
	free((void *)s);
	s = NULL;
	return ((const char *)new_str);
}

int	ft_quote(char const *str, int i)
{
	char	c;

	if (str[i - 1] == 34)
	{
		c = 34;
		while (str[i] && str[i] != 34 && str[i + 1])
			i++;
	}
	else
	{
		c = 39;
		while (str[i] && str[i] != 39 && str[i + 1])
			i++;
	}
	if (!str[i] || (str[i] != c && !str[i + 1]))
		return (-2);
	while (str[i + 1] && str[i + 1] != ' ' && str[i + 1] != '|'
		&& str[i + 1] != 34 && str[i + 1] != 39)
		i++;
	if (str[i + 1] == 34 || str[i + 1] == 39)
		i = ft_quote(str, i + 2);
	return (i);
}

char	**ft_cut(char const *s, char c, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i >= 0 && s[i])
	{
		k = i;
		if (s[i + 1] && s[i] != ' ' && s[i] != '|' && s[i] != 34 && s[i] != 39)
		{
			while (s[i + 1] && s[i + 1] != ' ' && s[i + 1] != '|'
				&& s[i] != 34 && s[i] != 39)
				i++;
		}
		if (s[i] == 34 || s[i] == 39)
			i = ft_quote(s, i + 1);
		if (i == -2)
			tab[j++] = ft_strdup("error");
		if (i >= 0 && s[i] != c)
			tab[j++] = ft_substr((char *) s, (unsigned int) k, i - k + 1);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

int	ft_ulti_wordcount(char *s, int i, int j, int result)
{
	if (s[0] == '\0')
		return (0);
	while (s[++i])
	{
		if (i != 0 && i != (int)ft_strlen(s) - 1 && s[i] == ' ')
		{
			j = i + 1;
			while (s[j] == ' ')
				j++;
			if (s[j] != ' ')
				result++;
			i = j - 1;
		}
		if (i != 0 && (s[i] == '|' || s[i] == '>' || s[i] == '<'))
		{
			if ((s[i + 1] == '>' && s[i] == '>')
				|| (s[i + 1] == '<' && s[i] == '<'))
				i++;
			i++;
			result++;
		}
	}
	if (s[i] != ' ')
		result++;
	return (result);
}

char	**ft_ultimate_split(char const *s, char c, t_vars *vars)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	s = ft_redir_space(s, -1, 0);
	tab = ft_calloc(ft_ulti_wordcount((char *)s, -1, 0, 1) + 1, sizeof(char *));
	tab = ft_cut(s, c, tab);
	free((void *)s);
	s = NULL;
	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "error", 4))
		{
			ft_free_split(tab);
			tab = NULL;
			ft_perror("Input", "invalid quotes", 1, vars);
			return (tab);
		}
		i++;
	}
	return (tab);
}
