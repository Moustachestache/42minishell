/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:51:41 by tremy             #+#    #+#             */
/*   Updated: 2023/10/26 14:52:01 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	*result;

	if (c == 0)
		return ((char *) &s[ft_strlen(s)]);
	l = 0;
	result = NULL;
	while (s[l])
	{
		if (s[l] == (char) c)
			result = (char *) &s[l];
		l++;
	}
	return (result);
}
