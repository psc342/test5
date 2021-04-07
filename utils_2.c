/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:56:59 by sangchpa          #+#    #+#             */
/*   Updated: 2021/04/07 21:22:25 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsignedintlen(unsigned int n)
{
	int		uint_len;

	uint_len = 1;
	while (n >= 10)
	{
		uint_len++;
		n = n / 10;
	}
	return (uint_len);
}

int			hexlen(unsigned int a)
{
	int		len;

	len = 1;
	while (a >= 16)
	{
		a = a / 16;
		len++;
	}
	return (len);
}

int			itohex(unsigned int a, char x)
{
	char	*set;
	char	tmp;
	int		print_size;

	print_size = hexlen(a);
	if (x == 'x')
		set = "0123456789abcdef";
	else if (x == 'X')
		set = "0123456789ABCDEF";
	while (a >= 16)
	{
		if (a >= 16)
		{
			itohex(a / 16, x);
			a = a % 16;
		}
		else
		{
			tmp = set[a / 16];
			write(1, &tmp, 1);
		}
	}
	write(1, &set[a], 1);
	return (print_size);
}

int			p_hexlen(unsigned long long a)
{
	int		len;

	len = 1;
	while (a >= 16)
	{
		a = a / 16;
		len++;
	}
	len = len + 2;
	return (len);
}

int			ptohex(unsigned long long a)
{
	char	*set;
	char	tmp;
	int		print_size;

	set = "0123456789abcdef";
	print_size = p_hexlen(a);
	while (a >= 16)
	{
		if (a >= 16)
		{
			ptohex(a / 16);
			a = a % 16;
		}
		else
		{
			tmp = set[a / 16];
			write(1, &tmp, 1);
		}
	}
	write(1, &set[a], 1);
	return (print_size);
}
