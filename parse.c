#include "pipex.h"
#include <stdio.h>

char    *get_path(char **env)
{
    int i;

    i = -1;
    while (env[++i])
        if (ft_strncmp("PATH",env[i], 4) == 0)
            return (env[i] + 5);
    return (NULL);
}
