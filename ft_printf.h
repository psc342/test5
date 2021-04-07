/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:08:45 by sangchpa          #+#    #+#             */
/*   Updated: 2021/04/07 21:23:48 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			star;
	char		type;
}				t_info;

int				ft_putchar(char c);
void			ft_putnbr(int n);
int				ft_putstr(char *s, int len);
int				processing(char *format, va_list ap, int i);
int				ft_intlen(int n);
void			opt_init(t_info *opt_list);
int				print_d_i(int d, t_info *opt_list);
int				print_d_i_minus(int d, t_info *opt_list);
int				print_c(int c, t_info *opt_list);
int				print_s(char *s, t_info *opt_list);
int				print_u(unsigned int d, t_info *opt_list);
int				print_u_minus(unsigned int d, t_info *opt_list);
void			ft_putunsigned(unsigned int n);
int				ft_unsignedintlen(unsigned int n);
int				hexlen(unsigned int a);
int				itohex(unsigned int a, char x);
int				print_x(unsigned int d, t_info *opt_list);
int				print_x_minus(unsigned int d, t_info *opt_list);
int				print_p(unsigned long long d, t_info *opt_list);
int				print_p_minus(unsigned long long d, t_info *opt_list);
int				print_per(t_info *opt_list);
int				ft_printf(const char *format, ...);
int				printf1(va_list ap, char *format);
int				parsing(va_list ap, int i, char *format, t_info *opt_list);
void			wid_and_pre(va_list ap, int i, char *format, t_info *opt_list);
int				print2(va_list ap, t_info *opt_list);
int				p_hexlen(unsigned long long a);
int				ptohex(unsigned long long a);
#endif
