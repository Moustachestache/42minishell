/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:45:38 by tremy             #+#    #+#             */
/*   Updated: 2023/10/27 13:45:46 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		return (0);
	while (s1[l] && s2[l] && l < n)
	{
		if (s1[l] != s2[l])
			return ((unsigned char) s1[l] - s2[l]);
		l++;
	}
	if ((s1[l] != '\0' || s2[l] != '\0') && l < n)
		return ((unsigned char) s1[l] - s2[l]);
	return (0);
}
