/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:33:53 by mjochum           #+#    #+#             */
/*   Updated: 2023/11/08 16:16:55 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include "../minishell.h"

t_command	*ft_create_commands(char **splited_line, t_vars *vars);
void		ft_command_list(char **s_line, t_command **list, size_t len);
t_env		**ft_init_env(char **env, t_vars *vars);
t_command	*ft_parsing(char *line, t_vars *vars);
char		*ft_strrchr(const char *s, int c);
size_t		ft_commands_size(char **splited_line, size_t t);
void		ft_env_addnode(char *valname, char *value, t_vars *vars);
void		ft_env_destroy(t_env **env);
int			ft_env_unset(char *valname, t_vars *vars);
t_vars		*ft_init_vars(char **env);
char		**ft_line_env(char **s_line, t_vars *vars);

#endif
