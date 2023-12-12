/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retvalsig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:21:45 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/08 11:24:34 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_lastsig;

void	ft_retvalsig(t_vars *vars)
{
	if (g_lastsig == SIGINT)
	{
		vars->retval = 128 + SIGINT;
		g_lastsig = 0;
	}
}
