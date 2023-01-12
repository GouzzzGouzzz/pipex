/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:41:37 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/24 17:13:37 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(int nb)
{
	char			nb_arr[10];
	int				i;
	unsigned int	nb_cast;

	nb_cast = nb;
	i = 0;
	if (nb_cast == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb_cast > 0)
	{
		nb_arr[i] = nb_cast % 10 + '0';
		nb_cast = nb_cast / 10;
		i++;
	}
	ft_print_arr_rev(i, nb_arr);
	return (i);
}
