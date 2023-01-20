#include "pipex.h"
#include <stdio.h>

char    *get_path(char **env)
{
    int i;

    i = -1;
    while (env[++i])
        if (ft_strncmp("PATH", env[i], 4) == 0)
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
    char    **full_cmd;

    cmd = ft_strjoin(path, "/");
    if (!cmd)
        return (NULL);
    ptr = cmd;
    full_cmd = ft_split(arg, ' ');
    cmd = ft_strjoin(cmd, full_cmd[0]);
    free(ptr);
    free_split(full_cmd);
    if (!cmd)
        return (NULL);
    return (cmd);
}

char **get_arg_cmd(char *args)
{
    char **cmd_arg;

    if (!args)
        return (NULL);
    cmd_arg = ft_split(args, ' ');
    if (!cmd_arg)
        return (NULL);
    if (cmd_arg[0] == NULL)
    {
        free_split(cmd_arg);
        return (NULL);
    }
    return (cmd_arg);
}

int error_handler(char *cmd, char **path)
{
    if (!cmd)
    {
        free_split(path);
        return (-1);
    }
    if (access(cmd, F_OK) == -1)
    {
        free(cmd);
        perror("Command not found");
        free_split(path);
        return (-1);
    }
    return (0);
}