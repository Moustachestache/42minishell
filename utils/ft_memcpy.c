/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:52 by tremy             #+#    #+#             */
/*   Updated: 2023/11/10 16:17:13 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	l;
	char	*dest_buffer;
	char	*src_buffer;

	if (!src && !dest)
		return (dest);
	dest_buffer = (char *) dest;
	src_buffer = (char *) src;
	l = 0;
	while (l < n)
	{
		dest_buffer[l] = src_buffer[l];
		l++;
	}
	return (dest);
}
