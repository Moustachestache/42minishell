/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:43:56 by tremy             #+#    #+#             */
/*   Updated: 2023/12/07 16:16:47 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start || len == 0)
		return (ft_strdup(""));
	while (s[start + i] && i < len)
		i++;
	tab = ft_calloc(i + 1, sizeof(char));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, &s[start], i + 1);
	return (tab);
}
