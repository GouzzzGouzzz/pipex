/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:21:25 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/31 14:30:51 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_fds(t_fd *file, int pipe[2])
{
	close(file->in_fd);
	close(file->out_fd);
	close(pipe[0]);
	close(pipe[1]);
}
