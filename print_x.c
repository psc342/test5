#include "ft_printf.h"

int print_x(unsigned int d, t_info *opt_list)
{
    int print_size;
	
	if (opt_list->zero == 1 && opt_list->dot == 1)
		opt_list->zero = 0;
	if (opt_list->minus == 1 && opt_list->zero == 1)
		opt_list->zero = 0;
    print_size = print_x_minus(d, opt_list);

    return (print_size);
}

int print_x_minus(unsigned int d, t_info *opt_list)
{
    int print_size;
    int wid_len;

    print_size = 0;
	if (opt_list->dot == 1 && opt_list->precision == 0)
	{
        if (opt_list->precision > hexlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - hexlen(d);
        if (opt_list->precision >= hexlen(d) && d < 0)
            wid_len--;
        if (d == 0)
            wid_len++;
        if (d == 0)
            print_size--;
        if (d != 0 && opt_list->minus == 1)
            itohex(d, opt_list->type);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
			wid_len--;
        }
        while ((opt_list->precision - hexlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        if (d != 0 && opt_list->minus == 0)
            itohex(d, opt_list->type);
	}
    else if(opt_list->minus == 0 && (opt_list->dot == 0 || opt_list->precision < 0))
    {
        wid_len = opt_list->width - hexlen(d);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        itohex(d, opt_list->type);
    }
    else if(opt_list->minus == 0 && opt_list->dot == 1 && opt_list->precision >= 0)
    {
        if (opt_list->precision > hexlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - hexlen(d);
        if (opt_list->precision >= hexlen(d) && d < 0)
            wid_len--;
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
        while ((opt_list->precision - hexlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        itohex(d, opt_list->type);
    }


    else if(opt_list->minus == 1 && (opt_list->dot == 0 || opt_list->precision <0))
    {
        wid_len = opt_list->width - hexlen(d);
        itohex(d, opt_list->type);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    else if(opt_list->minus == 1 && opt_list->dot == 1 && opt_list->precision >= 0)
    {
        
        if (opt_list->precision > (int)hexlen(d))
            wid_len = opt_list->width - opt_list->precision;
        else
            wid_len = opt_list->width - hexlen(d);
        if (opt_list->precision >= (int)hexlen(d) && d < 0)
            wid_len--;
        while ((opt_list->precision - hexlen(d)) > 0)
        {
            print_size = print_size + ft_putchar('0');
            opt_list->precision--;
        }
        itohex(d, opt_list->type);
        while(wid_len > 0)
        {
            if (opt_list->zero == 1)
            	print_size = print_size + ft_putchar('0');
			else
				print_size = print_size + ft_putchar(' ');
            wid_len--;
        }
    }
    return(print_size + hexlen(d));
}