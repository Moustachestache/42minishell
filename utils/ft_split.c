/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:31:03 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/02 15:41:10 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_wordcount(char *s, char c)
{
	size_t	result;
	size_t	i;
	size_t	j;

	i = 0;
	result = 1;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			j = i + 1;
			while (s[j] == c)
				j++;
			result++;
			i = j - 1;
		}
		i++;
	}
	if (s[0] == c && s[i - 1] == c)
		result = result - 2;
	if ((s [0] == c && s[i - 1] != c) || (s[0] != c && s[i - 1] == c))
		result = result - 1;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	tab = ft_calloc(ft_wordcount((char *)s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	tab[0] = NULL;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = i;
			while (s[i + 1] != c && s[i + 1] != '\0')
				i++;
			tab[j++] = ft_substr((char *) s, (unsigned int) k, i - k + 1);
		}
		i++;
	}
	return (tab);
}
