/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:34:55 by nmorandi          #+#    #+#             */
/*   Updated: 2022/12/01 16:50:55 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	reverse_and_print(long int nb)
{
	write(1, "-", 1);
	return (nb * -1);
}

int	ft_print_integer(int nb)
{
	char		nb_arr[10];
	int			i;
	long int	nb_cast;

	nb_cast = nb;
	i = 0;
	if (nb_cast == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb_cast < 0)
		nb_cast = reverse_and_print(nb_cast);
	while (nb_cast > 0)
	{
		nb_arr[i] = nb_cast % 10 + '0';
		nb_cast = nb_cast / 10;
		i++;
	}
	ft_print_arr_rev(i, nb_arr);
	if (nb < 0)
		return (i + 1);
	return (i);
}
