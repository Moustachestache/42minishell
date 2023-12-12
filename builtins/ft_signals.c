/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:45:45 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/08 16:26:48 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_lastsig;

static void	ft_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_lastsig = sig;
}

void	ft_heredoc_sig(int sig)
{
	if (sig == SIGINT)
	{
		printf("");
		g_lastsig = sig;
	}
}

//	renders signals moot
void	ft_mootsignal(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	ft_adult_sig(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_lastsig = sig;
	}
}

void	ft_signal_handler(t_vars *vars)
{
	struct sigaction	*sighandler;

	(void) vars;
	(void) sighandler;
	signal(SIGINT, &ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, SIG_DFL);
}
