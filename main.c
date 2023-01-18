#include "pipex.h"
#include <stdio.h>

// REMETTRE FLAG DAS LE MAKEFILE
static void	child_exec(int link[2], int in_fd, char **argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**path;

	i = -1;
	if (dup2(in_fd, 0) < 0)
		return ;
	if (dup2(link[1], 1) < 0)
		return ;
	close(link[0]);
	close(in_fd);
	path = ft_split(get_path(envp), ':');
	while (path[++i])
	{
		cmd = get_cmd(path[i], argv[2]);
		if (error_handler(cmd, path) == -1)
			exit(-1);
		execve(cmd, argv ,envp);	//need le cmd not found
		free(cmd);
	}
	free_split(path);
}

static void	parent_exec(int link[2], int out_fd, char **argv, char **envp)
{
	char	**path;
	char	*cmd;
	int		i;

	i = -1;
	waitpid(-1, NULL, 0);
	if (dup2(out_fd, 1) < 0)
		return ;
	if (dup2(link[0], 0) < 0)
		return ;
	close(link[1]);
	close(out_fd);
	path = ft_split(get_path(envp), ':');
	while (path[++i])
	{
		cmd = get_cmd(path[i], argv[3]);
		if (error_handler(cmd, path) == -1)
			exit(-1);
		execve(cmd, argv, envp);	//need le cmd not found
		free(cmd);
	}
	free_split(path);
	
}

static void join_process(int in_fd, int out_fd, char **envp, char **argv)
{
	int		link[2];
	int		pid;

	if(pipe(link) == -1)
		return ;
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
		child_exec(link, in_fd, argv, envp);
	else
		parent_exec(link, out_fd, argv, envp);
}

int main(int argc, char **argv, char **envp)
{
	int		in_fd;
	int		out_fd;

	if (argc != 5)
		return (0);
	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (in_fd == -1 || out_fd == -1)
		return (0);
	join_process(in_fd, out_fd, envp, argv);
}