/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:55:46 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/06 13:30:48 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_env		t_env;
typedef struct s_vars		t_vars;
typedef struct s_command	t_commands;
typedef struct s_pipeline	t_pipeline;

typedef struct s_env
{
	int		isunset;
	char	*name;
	char	*value;
}		t_env;

typedef struct s_command
{
	char	**args;
}		t_command;

typedef struct s_pipeline
{
	int		infile;
	int		outfile;
}		t_pipeline;

typedef struct s_vars
{
	int					ac;
	int					retval;
	int					varsfd[2];
	char				*home;
	t_env				**env;
	char				**env_tab;
	t_command			*commands;
	t_pipeline			*pipeline;
	struct sigaction	sighandler;
	size_t				commands_len;
}		t_vars;
