/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decidomatic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:28:49 by tremy             #+#    #+#             */
/*   Updated: 2023/12/06 11:54:10 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DECIDOMATIC_H
# define FT_DECIDOMATIC_H

# include "../minishell.h"

int		ft_decidomatic(t_vars *vars);
int		ft_exit_manager(t_command *command, t_vars *vars);
int		ft_echo_manager(t_command *command, t_vars *vars);
int		ft_cd_manager(t_command *command, t_vars *vars);
int		ft_export_manager(t_command *command, t_vars *vars);
int		ft_unset_manager(t_command *command, t_vars *vars);
int		ft_env_manager(t_command *command, t_vars *vars);
int		ft_execve(t_vars *vars, t_command *t_command);
int		ft_find_function(t_command *command, t_vars *vars);
//int		ft_perror(int errno_num, t_vars *vars);

#endif
