/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:41:53 by tremy             #+#    #+#             */
/*   Updated: 2023/11/14 16:26:44 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_tab_size(char **tab)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		res += j;
		i++;
	}
	return (res);
}

char	*ft_ultimate_join(char **tab)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = ft_tab_size(tab);
	str = ft_calloc(l + 1, sizeof(char));
	while (tab[i])
	{
		ft_strlcpy(&str[ft_strlen(str)], tab[i], ft_strlen(tab[i]) + 1);
		i++;
	}
	ft_free_split(tab);
	return (str);
}
