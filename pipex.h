/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:08 by gouz              #+#    #+#             */
/*   Updated: 2023/01/31 17:43:53 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_file{
	int	in_fd;
	int	out_fd;
}		t_fd;

size_t	ft_strlen(const char *s);
char	*get_path(char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*get_cmd(char *path, char *arg);
char	**get_arg_cmd(char *args);
int		msg_error(char *str);
void	free_split(char **split);
void	close_all_fds(t_fd *file, int pipe[2]);

#endif