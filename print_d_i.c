#include "ft_printf.h"

int print_d_i(int d, t_info *opt_list)
{
    int print_size;

	if (opt_list->zero == 1 && opt_list->dot == 1)
		opt_list->zero = 0;
	if (opt_list->minus == 1 && opt_list->zero == 1)
		opt_list->zero = 0;
    print_size = print_d_i_minus(d, opt_list);

    return (print_size);
}

int print_d_i_minus(int d, t_info *opt_list)
{
    int print_size;
    int wid_len;

    print_size = 0;

    if (opt_list->dot == 1 && opt_list->precision == 0)
	{
        if (opt_list->precision > ft_intlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - ft_intlen(d);
        if (opt_list->precision >= ft_intlen(d) && d < 0)
            wid_len--;
        if (d == 0)
            wid_len++;
        if (d == 0)
            print_size--;
        if (d != 0 && opt_list->minus == 1)
            ft_putnbr(d);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
			wid_len--;
        }
        while ((opt_list->precision - ft_intlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        if (d != 0 && opt_list->minus == 0)
            ft_putnbr(d);
	}
	else if(opt_list->minus == 0 && (opt_list->dot == 0 || opt_list->precision <0))
    {
        wid_len = opt_list->width - ft_intlen(d);
        if (d < 0 && opt_list->zero == 1)
        {
            ft_putchar('-');
            print_size++;
            d = d * -1;
        }
		while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        if (d == -2147483648 && opt_list->zero == 1)
            print_size--;
        if (d == -2147483648 && opt_list->zero == 1)
            write(1, "2147483648", 10);
        else
            ft_putnbr(d);
        
    }
	
    else if(opt_list->minus == 0 && opt_list->dot == 1 && opt_list->precision > 0)
    {
        if (opt_list->precision > ft_intlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - ft_intlen(d);
        if (opt_list->precision >= ft_intlen(d) && d < 0)
            wid_len--;
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
			wid_len--;
        }
        if (d < 0)
        {
            ft_putchar('-');
            print_size++;
            d = d * -1;
        }
        while ((opt_list->precision - ft_intlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        if (d == -2147483648)
            print_size--;
        if (d == -2147483648)
            write(1, "2147483648", 10);
        else
            ft_putnbr(d);
    }


    else if(opt_list->minus == 1 && (opt_list->dot == 0 || opt_list->precision <0))
    {
        wid_len = opt_list->width - ft_intlen(d);
        ft_putnbr(d);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
			wid_len--;
        }
    }
    else if(opt_list->minus == 1 && opt_list->dot == 1 && opt_list->precision > 0)
    {
        
        if (opt_list->precision > ft_intlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - ft_intlen(d);
        if (opt_list->precision >= ft_intlen(d) && d < 0)
            wid_len--;
        if (d < 0)
        {
            ft_putchar('-');
            print_size++;
            d = d * -1;
        }
        while ((opt_list->precision - ft_intlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        if (d == -2147483648)
            print_size--;
        if (d == -2147483648)
            write(1, "2147483648", 10);
        else
            ft_putnbr(d);
        while(wid_len > 0)
        {
			if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }

    return(print_size + ft_intlen(d));
}