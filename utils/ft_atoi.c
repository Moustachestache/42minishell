/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:57:58 by tremy             #+#    #+#             */
/*   Updated: 2023/11/03 13:08:03 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	res;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		if ((nptr[i] < '0' || nptr[i] > '9')
			|| (sign == 1 && (res * 10 + nptr[i] - '0') > INT_MAX)
			|| (sign == -1
				&& ((res * 10 + nptr[i] - '0') * (-1)) < INT_MIN))
			return ('\0');
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
