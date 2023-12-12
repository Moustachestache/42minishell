/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:08:32 by tremy             #+#    #+#             */
/*   Updated: 2023/10/31 10:59:10 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*tab;

	length = ft_strlen(s);
	i = 0;
	tab = ft_calloc(length + 1, sizeof(char));
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}
