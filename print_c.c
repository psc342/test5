/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:22:40 by sangchpa          #+#    #+#             */
/*   Updated: 2021/04/07 21:18:23 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_c(int c, t_info *opt_list)
{
	int		print_size;

	print_size = 0;
	if (opt_list->minus == 1 && opt_list->type == 'c')
		print_size += ft_putchar(c);
	opt_list->width--;
	while (opt_list->width > 0)
	{
		if (opt_list->zero == 1 && opt_list->minus != 1)
			print_size += ft_putchar('0');
		else
			print_size += ft_putchar(' ');
		opt_list->width--;
	}
	if (opt_list->minus == 0 && opt_list->type == 'c')
		print_size += ft_putchar(c);
	return (print_size);
}

void		opt_init(t_info *opt_list)
{
	opt_list->minus = 0;
	opt_list->zero = 0;
	opt_list->width = 0;
	opt_list->dot = 0;
	opt_list->precision = 0;
	opt_list->type = 0;
	return ;
}
