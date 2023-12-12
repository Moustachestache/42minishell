/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:11:55 by mjochum           #+#    #+#             */
/*   Updated: 2023/10/29 17:26:17 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*r;

	r = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;
	j = 0;
	if (r == NULL)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		r[i] = s2[j];
		j++;
		i++;
	}
	return (r);
}
/*
int	main(void)
{
	char str[100] = "sept cent slips ";
	char str1[30] = "dans ton cul";
	printf("%s", ft_strjoin(str,str1));
}*/
