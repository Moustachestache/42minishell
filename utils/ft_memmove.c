/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:14:56 by tremy             #+#    #+#             */
/*   Updated: 2023/11/10 16:15:21 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_buffer;
	char	*src_buffer;

	if (!dest && !src)
		return (dest);
	dest_buffer = (char *) dest;
	src_buffer = (char *) src;
	if (src_buffer > dest_buffer)
		return (ft_memcpy(dest, src, n));
	while (n != 0)
	{
		dest_buffer[n - 1] = src_buffer[n - 1];
		n--;
	}
	return (dest);
}
