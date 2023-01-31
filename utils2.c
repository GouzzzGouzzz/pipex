/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:21:25 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/31 15:02:13 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_fds(t_fd *file, int pipe[2])
{
	if (file->in_fd != -1)
		close(file->in_fd);
	if (file->out_fd != -1)
		close(file->out_fd);
	if (!pipe)
		return ;
	if (pipe[0] != -1)
		close(pipe[0]);
	if (pipe[1] != -1)
		close(pipe[1]);
}
