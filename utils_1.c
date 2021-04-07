/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:51:05 by sangchpa          #+#    #+#             */
/*   Updated: 2021/04/07 20:54:56 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putchar(char c)
{
	int		i;

	i = 0;
	i = i + write(1, &c, 1);
	return (i);
}

int			ft_putstr(char *s, int len)
{
	int		print_size;
	int		i;

	print_size = 0;
	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0' && i < len)
	{
		print_size = print_size + write(1, &s[i], 1);
		i++;
	}
	return (print_size);
}

void		ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	return ;
}

int			ft_intlen(int n)
{
	int		int_len;

	int_len = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		int_len++;
		n = n * -1;
	}
	while (n >= 10)
	{
		int_len++;
		n = n / 10;
	}
	return (int_len);
}

void		ft_putunsigned(unsigned int n)
{
	char	c;

	if (n == 4294967295)
		write(1, "4294967295", 10);
	else
	{
		if (n >= 10)
			ft_putunsigned(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	return ;
}
