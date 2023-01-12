/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:28:53 by nmorandi          #+#    #+#             */
/*   Updated: 2022/12/07 13:48:21 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_output(int flag, va_list ap, char c)
{
	int	len;

	len = 0;
	if (flag == 0)
		ft_putchar(c);
	if (flag == 1)
		len = ft_putstr(va_arg(ap, char *));
	if (flag == 2)
		len = ft_print_address(va_arg(ap, uintptr_t));
	if (flag == 3)
		len = ft_print_integer(va_arg(ap, int));
	if (flag == 4)
		len = ft_print_unsigned(va_arg(ap, unsigned int));
	if (flag == 5)
		len = ft_print_hexa(va_arg(ap, int), 1);
	if (flag == 6)
		len = ft_print_hexa(va_arg(ap, int), 0);
	if (flag == 7)
		len = ft_putchar('%');
	if (flag == 8)
		len = ft_putchar(va_arg(ap, int));
	return (len);
}

static int	ft_cancel_flaglen(int flag, int curr_len)
{
	if (flag != 0)
		return (curr_len - 2);
	return (curr_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		flag;
	int		print_len;

	flag = 0;
	i = 0;
	print_len = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			flag = ft_get_flag(str[i + 1]);
		print_len += ft_flag_output(flag, ap, str[i]);
		if (flag != 0)
			i++;
		print_len = ft_cancel_flaglen(flag, print_len);
		i++;
		flag = 0;
	}
	va_end(ap);
	return (print_len + i);
}
