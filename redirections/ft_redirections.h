/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:47:30 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/07 11:33:00 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REDIRECTIONS_H
# define FT_REDIRECTIONS_H

# include "../minishell.h"

//	functions goes 'ere
int			ft_fork(int forkid, size_t i, int *fd, t_vars *vars);
t_pipeline	*ft_buildpipeline(t_vars *vars);
int			ft_fork(int forkid, size_t i, int *fd, t_vars *vars);
void		ft_redirections(t_pipeline pipeline, t_vars *vars);

#endif
