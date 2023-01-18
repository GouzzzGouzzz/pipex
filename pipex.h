#ifndef PIPEX_H
#define PIPEX_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char    *get_path(char **env);
void    free_split(char **split);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char    *get_cmd(char *path, char *arg);
char    **get_arg_cmd(char *args);
int     error_handler(char *cmd, char **path);
#endif