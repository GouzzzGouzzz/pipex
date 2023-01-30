/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:40:08 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/30 19:21:23 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_acces(char **path, char *arg)
{
	char	*cmd;
	int		i;

	i = -1;
	if (!path)
		return (NULL);
	while (path[++i])
	{
		cmd = get_cmd(path[i], arg);
		if (!cmd)
			return (NULL);
		if (access(cmd, F_OK) == 0)
		{
			return (cmd);
		}
		free(cmd);
	}
	return (NULL);
}

static int	child_exec(int link[2], int in_fd, int out_fd,char **argv, char **envp)
{
	char	*cmd;
	char	**path;
	char	**cmd_arg;

	if (dup2(in_fd, 0) < 0)
		return (msg_error("Dup2 failed"));
	if (dup2(link[1], 1) < 0)
		return (msg_error("Dup2 failed"));
	close(link[1]);
	close(link[0]);
	close(in_fd);
	close(out_fd);
	path = ft_split(get_path(envp), ':');
	cmd_arg = get_arg_cmd(argv[2]);
	cmd = check_acces(path, argv[2]);
	free_split(path);
	if (!cmd || !cmd_arg)
	{
		free_split(cmd_arg);
		msg_error("Command not found\n");
		exit(EXIT_FAILURE);
	}
	execve(cmd, cmd_arg, envp);
	return (0);
}

static int	sec_child_exec(int link[2], int out_fd, int in_fd,char **argv, char **envp)
{
	char	**path;
	char	*cmd;
	char	**cmd_arg;

	if (dup2(out_fd, 1) < 0)
		return (msg_error("Dup2 failed"));
	if (dup2(link[0], 0) < 0)
		return (msg_error("Dup2 failed"));
	close(link[1]);
	close(link[0]);
	close(in_fd);
	close(out_fd);
	path = ft_split(get_path(envp), ':');
	cmd_arg = get_arg_cmd(argv[3]);
	cmd = check_acces(path, argv[3]);
	free_split(path);
	if (!cmd || !cmd_arg)
	{
		free_split(cmd_arg);
		msg_error("Command not found\n");
		exit(EXIT_FAILURE);
	}
	execve(cmd, cmd_arg, envp);
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
		child_exec(link, in_fd, out_fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		sec_child_exec(link, out_fd, in_fd, argv, envp);
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
		return (msg_error("Error : File error\n"));
	out_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (out_fd == -1)
	{
		close(in_fd);
		return (msg_error("Error : File error\n"));
	}
	if (join_process(in_fd, out_fd, envp, argv) == -1)
		return (msg_error("Error : process error\n"));
	close(in_fd);
	close(out_fd);
	return (0);
}
