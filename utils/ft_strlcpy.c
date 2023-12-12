/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:45:17 by tremy             #+#    #+#             */
/*   Updated: 2023/10/25 17:02:10 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	l;

	l = 0;
	if (size != 0)
	{
		while (src[l] && l < size - 1)
		{
			dest[l] = src[l];
			l++;
		}
		dest[l] = '\0';
	}
	return (ft_strlen(src));
}
