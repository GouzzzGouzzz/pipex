#include "pipex.h"
#include <stdio.h>


static void	child_exec(char *path, int in_fd) //exec avec le path faire commande 1 puis envoyer dans le daron avec le truc du pipe
{

}

static void	parent_exec(char *path, int out_fd)//exec avec le path, recuperer du child et envoyer le res dans le file out
{

}

int main(int argc, char **argv, char **envp)
{
	int in_fd;
	int out_fd;
	char **path;

	if (argc != 5)
		return (0);
	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR);
	if (in_fd == -1 || out_fd == -1)
		return (0); // fd is open
	path = ft_split(envp[24], ':'); // trouver mieux car pas safe jpense
	printf("%s\n",path[0]);
}