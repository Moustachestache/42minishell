/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:19:23 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/08 11:23:48 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "../minishell.h"

struct	s_vars;

int		ft_isposix_char(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		ft_add_env(char *name, char *value, t_vars *vars);
int		ft_is_empty(char *str, char c, t_vars *vars);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_validate_env(char *env, size_t len, t_vars *vars);
int		ft_heredoc(char *delimiter, t_vars *vars);
int		ft_perror(char *info, char *extrainfo, int perrno, t_vars *vars);
char	*ft_tilde(char *input, t_vars *vars);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_ultimate_split(char const *s, char c, t_vars *vars);
size_t	ft_wordcount(char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	ft_free_split(char **split);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_print_split(char **s_line);
void	ft_print_command(t_vars *vars);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_retvalsig(t_vars *vars);
char	*ft_itoa(int n);
void	ft_get_prompt(t_vars *vars);
void	ft_free_commands(t_vars *vars, t_command **commands, size_t l);
void	ft_free_pipeline(t_pipeline *pipeline);
t_env	*ft_fetch_env(char *varname, t_vars *vars);
t_env	*ft_forcefetch_env(char *varname, t_vars *vars);
char	*ft_ultimate_join(char **tab);
char	**ft_unredir_command(char **cmd);

#endif
