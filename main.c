#include "pipex.h"
#include <stdio.h>


	// je check si le premier fd existe
	// j execute la 1ere commande into je pipe la 2nd
	// je copie ce qui sort du pipe dans le fd de fin


static void	first_cmd(int fd)
{

}

int main(int argc, char **argv)
{
	int in_fd;

	if (argc != 5)
		return (0);
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
		return (0); // fd is open
}