/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:08:01 by gouzgouz          #+#    #+#             */
/*   Updated: 2022/10/24 17:13:39 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(uintptr_t address)
{
	int					i;
	char				*hexa_set;
	char				address_arr[16];

	hexa_set = "0123456789abcdef";
	i = 0;
	if (!address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (address > 0)
	{
		address_arr[i] = hexa_set[(address % 16)];
		address = address / 16;
		i++;
	}
	ft_print_arr_rev(i, address_arr);
	return (i + 2);
}
