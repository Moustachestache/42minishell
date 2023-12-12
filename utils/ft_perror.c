/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:35:09 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/06 13:59:24 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//
//		error:		minishell:	unrecognised variable	(1)
//		*env->value	*info		*extrainfo				*perrno
int	ft_perror(char *info, char *extrainfo, int perrno, t_vars *vars)
{
	t_env	*env;

	if (perrno == 0)
		return (0);
	env = ft_fetch_env("SHELLNAME", vars);
	if (env)
		printf("%s: ", env->value);
	else
		printf("🤫: ");
	if (info)
		printf("%s: ", info);
	if (extrainfo)
		printf("%s", extrainfo);
	if (errno != 0)
	{
		strerror(errno);
	}
	printf("\n");
	return (perrno);
}
