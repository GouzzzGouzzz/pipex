#include "pipex.h"
#include <stdio.h>

// REMETTRE FLAG DAS LE MAKEFILE
static void	child_exec(int link[2], int in_fd, char **argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**path;

	i = -1;
	if (dup2(in_fd, 0) == -1) //lire sur le infile (stdin = 0) et error
		return ;
	if (dup2(link[1], 0) == -1)
		return ;
	path = ft_split(get_path(envp), ':'); //need le free func a la fin
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], argv[2]);
		if (!cmd)
			return ;
		execve(path[i], argv ,envp);
		free(cmd);
	}
}

static void	parent_exec(int link[2], int out_fd, char **argv, char **envp)
{
	char	**path;

	waitpid(-1, NULL, 0);
	if (dup2(out_fd, 1) == -1) //lire sur le outfile(stdout = 1) et error
		return ;
	if (dup2(link[0], 1) == -1)
		return ;
	path = ft_split(get_path(envp), ':'); //need le free func a la fin
	//boucle sur le path si rien apes tout parcours -> error cmd not found
}

static void join_process(int in_fd, int out_fd, char **envp, char **argv)
{
	int		link[2];
	int		pid;

	if(pipe(link) == -1) // error
		return ;
	pid = fork();
	if (pid < 0) //error
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
	out_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR);
//	if (in_fd == -1 || out_fd == -1)
//		return (0); // fd is open
	join_process(in_fd, out_fd, envp, argv);
}