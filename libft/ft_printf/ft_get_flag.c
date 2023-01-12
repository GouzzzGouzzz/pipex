/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:34:29 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/24 17:13:41 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_flag(char c)
{
	if (c == 's')
		return (1);
	if (c == 'p')
		return (2);
	if (c == 'd' || c == 'i')
		return (3);
	if (c == 'u')
		return (4);
	if (c == 'x')
		return (5);
	if (c == 'X')
		return (6);
	if (c == '%')
		return (7);
	if (c == 'c')
		return (8);
	return (0);
}
