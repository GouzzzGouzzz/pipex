/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:40:08 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/31 16:15:15 by nmorandi         ###   ########.fr       */
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
			return (cmd);
		free(cmd);
	}
	return (NULL);
}

static int	child_exec(int link[2], t_fd *file, char **argv, char **envp)
{
	char	*cmd;
	char	**path;
	char	**cmd_arg;

	if (dup2(file->in_fd, 0) < 0) // cause le double mais evite des erreurs
		return (msg_error("Error : Dup2 failed\n"));
	if (dup2(link[1], 1) < 0)
		return (msg_error("Error : Dup2 failed\n"));
	close_all_fds(file, link);
	path = ft_split(get_path(envp), ':');
	cmd_arg = get_arg_cmd(argv[2]);
	cmd = check_acces(path, argv[2]);
	free_split(path);
	if (!cmd || !cmd_arg)
	{
		if (cmd_arg)
			free_split(cmd_arg);
		if (cmd)
			free(cmd);
		return (msg_error("Error : Command not found \n"));
	}
	execve(cmd, cmd_arg, envp);
	exit(EXIT_SUCCESS);
}

static int	sec_child_exec(int link[2], t_fd *file, char **argv, char **envp)
{
	char	**path;
	char	*cmd;
	char	**cmd_arg;

	if (dup2(file->out_fd, 1) < 0)
		return (msg_error("Error : Dup2 failed\n"));
	if (dup2(link[0], 0) < 0)
		return (msg_error("Error : Dup2 failed\n"));
	close_all_fds(file, link);
	path = ft_split(get_path(envp), ':');
	cmd_arg = get_arg_cmd(argv[3]);
	cmd = check_acces(path, argv[3]);
	free_split(path);
	if (!cmd || !cmd_arg)
	{
		if (cmd_arg)
			free_split(cmd_arg);
		if (cmd)
			free(cmd);
		return (msg_error("Error : Command not found\n"));
	}
	execve(cmd, cmd_arg, envp);
	exit(EXIT_SUCCESS);
}

static int	join_process(t_fd *file, char **envp, char **argv)
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
		child_exec(link, file, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		sec_child_exec(link, file, argv, envp);
	close(link[0]);
	close(link[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_fd	file;

	if (argc != 5)
		return (0);
	file.in_fd = open(argv[1], O_RDONLY);
	file.out_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (file.out_fd == -1)
	{
		close(file.in_fd);
		return (msg_error("Error : File error\n"));
	}
	if (join_process(&file, envp, argv) == -1)
	{
		close_all_fds(&file, NULL);
		return (msg_error("Error : process error\n"));
	}
	close_all_fds(&file, NULL);
	return (0);
}
