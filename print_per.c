/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:43:26 by sangchpa          #+#    #+#             */
/*   Updated: 2021/04/07 21:19:12 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_per(t_info *opt_list)
{
	int		print_size;

	print_size = 0;
	if (opt_list->minus == 1 && opt_list->type == '%')
		print_size += ft_putchar('%');
	opt_list->width--;
	while (opt_list->width > 0)
	{
		if (opt_list->zero == 1 && opt_list->minus != 1)
			print_size += ft_putchar('0');
		else
			print_size += ft_putchar(' ');
		opt_list->width--;
	}
	if (opt_list->minus == 0 && opt_list->type == '%')
		print_size += ft_putchar('%');
	return (print_size);
}
