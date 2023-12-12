/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:01:16 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/07 10:29:45 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	allocates maximu size of path to buffer
//	writes pwd to buffer
//	print, free, bobs ur uncle
int	ft_pwd(t_vars *vars)
{
	int		retval;
	char	*buf;

	retval = 1;
	(void) vars;
	buf = ft_calloc(PATH_MAX, sizeof(char));
	if (getcwd(buf, PATH_MAX) == NULL)
	{
		retval = 1;
		ft_perror("pwd", buf, 1, vars);
	}
	free(buf);
	buf = NULL;
	return (retval);
}
