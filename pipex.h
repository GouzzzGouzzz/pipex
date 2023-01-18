#ifndef PIPEX_H
#define PIPEX_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <errno.h> //pour check error avec le acces
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
char    *get_path(char **env);
void    free_split(char **split);

#endif