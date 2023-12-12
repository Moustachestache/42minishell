/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:47:55 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/07 18:56:28 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_redirections(t_pipeline pipeline, t_vars *vars)
{
	if (pipeline.infile == -1)
		ft_exit(1, vars);
	if (pipeline.infile != STDIN_FILENO)
	{
		if (dup2(pipeline.infile, STDIN_FILENO) != pipeline.infile)
			close(pipeline.infile);
		else
			ft_perror("infile", NULL, 1, vars);
	}
	if (pipeline.outfile != STDOUT_FILENO)
	{
		if (dup2(pipeline.outfile, STDOUT_FILENO) != pipeline.outfile)
			close(pipeline.outfile);
		else
			ft_perror("outfile", NULL, 1, vars);
	}
}
