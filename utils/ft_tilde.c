/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:13:58 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/07 10:50:10 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	manages tilde (~) when in command line
//	~name		(user)
//	~/folder/	(folder in own)
//	~		(empty)
//	!!!
char	*ft_tilde(char *input, t_vars *vars)
{
	char	*retval;
	char	*temp;

	temp = NULL;
	if (!input || input[0] != '~')
		retval = NULL;
	if (input[1] == '\0')
		retval = ft_strdup(vars->home);
	else if (input[1] == '/')
		retval = ft_strjoin(vars->home, input + 1);
	else
	{
		temp = ft_strjoin(vars->home, "/../");
		retval = ft_strjoin(temp, input + 1);
		free (temp);
		temp = NULL;
	}
	return (retval);
}
