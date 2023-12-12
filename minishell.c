/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:14:37 by tremy             #+#    #+#             */
/*   Updated: 2023/12/08 16:15:22 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_lastsig;

void	ft_commander(t_vars *vars)
{
	if (vars->commands == NULL)
		vars->retval = 1;
	else
	{
		vars->retval = ft_decidomatic(vars);
		ft_free_commands(vars, &vars->commands, vars->commands_len);
	}
	ft_retvalsig(vars);
}

int	main(int argc, char **argv, char **env)
{
	t_vars	*vars;
	char	*line;

	vars = ft_init_vars(env);
	while (1)
	{
		ft_signal_handler(vars);
		ft_get_prompt(vars);
		line = readline(ft_forcefetch_env("PROMPT", vars)->value);
		if (!ft_is_empty((char *)line, ' ', vars))
		{
			add_history(line);
			vars->commands = ft_parsing(line, vars);
			if (vars->commands)
			{
				ft_commander(vars);
				ft_free_pipeline(vars->pipeline);

			}
			ft_retvalsig(vars);
		}
		else
			free(line);
	}
	(void)argv;
	(void)argc;
	(void)g_lastsig;
	return (0);
}
