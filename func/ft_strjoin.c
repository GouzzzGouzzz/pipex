/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:47 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/18 04:25:41 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	int		temp;

	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + 1 + ft_strlen(s2)) * sizeof(char));
	if (!(str))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	temp = i;
	i = 0;
	while (s2[i])
	{
		str[temp + i] = s2[i];
		i++;
	}
	str[temp + i] = '\0';
	return (str);
}
