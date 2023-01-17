#ifndef PIPEX_H
#define PIPEX_H
# include "libft/libft.h"
# include <errno.h> //pour check error avec le acces
# include <sys/wait.h>

char    *get_path(char **env);
void    free_split(char **split);

#endif