/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:41:22 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/08 11:48:38 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

# include "../minishell.h"

int		ft_cd(char *dir, t_vars *vars);
int		ft_echo(char **data, char *arg, t_vars *vars);
int		ft_env(char **data, t_vars *vars);
int		ft_export(char **cmd, t_vars *vars);
int		ft_unset(char *str, t_vars *vars);
int		ft_pwd(t_vars *vars);
int		ft_exit(int exit_value, t_vars *vars);
void	ft_signal_handler(t_vars *vars);
void	ft_adult_sig(int sig);
void	ft_heredoc_sig(int sig);
void	ft_mootsignal(void);

#endif
