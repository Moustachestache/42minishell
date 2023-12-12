/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:04:07 by tremy             #+#    #+#             */
/*   Updated: 2023/12/07 15:14:56 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_get_prompt(t_vars *vars)
{
	char	*first_prompt;
	char	*prompt;
	char	*current_dir;

	current_dir = ft_calloc(PATH_MAX, sizeof(char));
	getcwd(current_dir, PATH_MAX);
	first_prompt = ft_strjoin(ft_forcefetch_env("SHELLNAME", vars)->value, \
		current_dir);
	prompt = ft_strjoin(first_prompt, " -> ");
	if (!ft_fetch_env("PROMPT", vars))
		ft_add_env("PROMPT", prompt, vars);
	else
	{
		free(ft_fetch_env("PROMPT", vars)->value);
		ft_fetch_env("PROMPT", vars)->value = ft_strdup(prompt);
	}
	free(prompt);
	free(first_prompt);
	free(current_dir);
	prompt = NULL;
	first_prompt = NULL;
	current_dir = NULL;
}
