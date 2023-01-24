/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:42:34 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/24 18:24:23 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (ft_strncmp("PATH", env[i], 4) == 0)
			return (env[i] + 5);
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

char	*get_cmd(char *path, char *arg)
{
	char	*cmd;
	char	*ptr;
	char	**full_cmd;

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

char	**get_arg_cmd(char *args)
{
	char	**cmd_arg;

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

int	msg_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	return (-1);
}
