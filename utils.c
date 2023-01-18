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

void    free_split(char **split)
{
    int i;

    i = -1;
    while(split[++i])
        free(split[i]);
    free(split);
}

char    *get_cmd(char *path, char *arg)
{
    char    *cmd;
    char    *ptr;

    cmd = ft_strjoin(path, "/");
    if (!cmd)
        return (NULL);
    ptr = cmd;
    cmd = ft_strjoin(cmd, arg);
    free(ptr);
    if (!cmd)
        return (NULL);
    return (cmd);
}

int error_handler(char *cmd, char **path)
{
    if (!cmd)
        return (-1);
    if (access(cmd, F_OK) == -1)
    {
        free(cmd);
        perror("Command not found");
        free_split(path);
        return (-1);
    }
    return (0);
}