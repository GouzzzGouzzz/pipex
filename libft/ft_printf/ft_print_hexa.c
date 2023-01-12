/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:02:38 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/24 17:13:38 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(int nb, int lower_case)
{
	unsigned int		nb_cast;
	int					i;
	char				*hexa_set;
	char				hexa_arr[10];

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hexa_set = "0123456789ABCDEF";
	i = 0;
	nb_cast = nb;
	while (nb_cast > 0)
	{
		if (nb_cast % 16 > 9 && lower_case)
			hexa_arr[i] = hexa_set[(nb_cast % 16)] + 32;
		else
			hexa_arr[i] = hexa_set[(nb_cast % 16)];
		nb_cast = nb_cast / 16;
		i++;
	}
	ft_print_arr_rev(i, hexa_arr);
	return (i);
}
