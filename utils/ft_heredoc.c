/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:31:49 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/08 11:51:31 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_heredocloop(char *line, char *delimiter, int writefd)
{
	while (ft_strncmp(line, delimiter, -1) != 0)
	{
		write(writefd, line, ft_strlen(line));
		free(line);
		line = NULL;
		write(writefd, "\n", 1);
		line = readline("heredoc> ");
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	ft_heredoc(char *delimiter, t_vars *vars)
{
	int		pipefd[2];
	int		pid;
	char	*line;

	(void) vars;
	pipe(pipefd);
	signal(SIGINT, ft_heredoc_sig);
	pid = fork();
	if (pid == -1)
		return (ft_perror("heredoc", "fork", 1, vars));
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		close(pipefd[0]);
		line = readline("heredoc> ");
		ft_heredocloop(line, delimiter, pipefd[1]);
		close(pipefd[1]);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	close(pipefd[1]);
	return (pipefd[0]);
}
