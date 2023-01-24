/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:40:08 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/24 18:20:57 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_acces(char **path, char *arg)
{
	char	*cmd;
	int		i;

	i = -1;
	if (!path)
		return (-1);
	while (path[++i])
	{
		cmd = get_cmd(path[i], arg);
		if (!cmd)
			return (-1);
		if (access(cmd, F_OK) == 0)
		{
			free(cmd);
			return (1);
		}
		free(cmd);
	}
	return (msg_error("Command not found"));
}

static int	child_exec(int link[2], int in_fd, char **argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**path;
	char	**cmd_arg;

	i = -1;
	if (dup2(in_fd, 0) < 0)
		return (msg_error("Dup2 failed"));
	if (dup2(link[1], 1) < 0)
		return (msg_error("Dup2 failed"));
	close(link[0]);
	path = ft_split(get_path(envp), ':');
	if (!check_acces(path, argv[2]))
		return (-1);
	cmd_arg = get_arg_cmd(argv[2]);
	while (path[++i])
	{
		cmd = get_cmd(path[i], argv[2]);
		execve(cmd, cmd_arg, envp);
		free(cmd);
	}
	free_split(path);
	free_split(cmd_arg);
	return (0);
}

static int	sec_child_exec(int link[2], int out_fd, char **argv, char **envp)
{
	char	**path;
	char	*cmd;
	char	**cmd_arg;
	int		i;

	i = -1;
	if (dup2(out_fd, 1) < 0)
		return (msg_error("Dup2 failed"));
	if (dup2(link[0], 0) < 0)
		return (msg_error("Dup2 failed"));
	close(link[1]);
	path = ft_split(get_path(envp), ':');
	if (!check_acces(path, argv[3]))
		return (-1);
	cmd_arg = get_arg_cmd(argv[3]);
	while (path[++i])
	{
		cmd = get_cmd(path[i], argv[3]);
		execve(cmd, cmd_arg, envp);
		free(cmd);
	}
	free_split(path);
	free_split(cmd_arg);
	return (0);
}

static int	join_process(int in_fd, int out_fd, char **envp, char **argv)
{
	int		link[2];
	int		pid;
	int		pid2;

	if (pipe(link) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
		child_exec(link, in_fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		sec_child_exec(link, out_fd, argv, envp);
	close(link[0]);
	close(link[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		in_fd;
	int		out_fd;

	if (argc != 5)
		return (0);
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
		return (0);
	out_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (out_fd == -1)
	{
		close(in_fd);
		return (0);
	}
	if (join_process(in_fd, out_fd, envp, argv) == -1)
		return (msg_error("An error occured"));
	close(in_fd);
	close(out_fd);
	return (0);
}
