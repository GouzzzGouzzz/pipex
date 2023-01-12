/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:55:13 by nmorandi          #+#    #+#             */
/*   Updated: 2022/12/01 16:50:23 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_get_flag(char c);
int		ft_print_address(uintptr_t address);
void	ft_print_arr_rev(int size, char *tab);
int		ft_print_hexa(int nb, int lower_case);
int		ft_print_integer(int nb);
int		ft_print_unsigned(int nb);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
#endif
