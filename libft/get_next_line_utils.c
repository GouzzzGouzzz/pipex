/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:13:23 by nmorandi          #+#    #+#             */
/*   Updated: 2022/12/15 14:42:53 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (c == '\0')
		return ((char *)&s[len]);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_store_extra(char *extra, char *to_store, ssize_t len)
{
	char	*new_str;
	ssize_t	i;
	int		temp;

	temp = ft_strlen(extra) + len + 1;
	new_str = malloc(sizeof(char) * (temp));
	if (!new_str)
		return (NULL);
	i = 0;
	while (extra[i])
	{
		new_str[i] = extra[i];
		i++;
	}
	temp = i;
	i = 0;
	while (to_store[i] && len > i)
	{
		new_str[temp + i] = to_store[i];
		i++;
	}
	free(extra);
	new_str[temp + i] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	long unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (NULL);
	while (i < len && s[start + i] != '\0')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	i = -1;
	while (++i < len && s[start + i] != '\0')
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
