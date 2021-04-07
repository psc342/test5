#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int b;

	a = ft_printf("|%4d|", -12);
	ft_printf("\nft_printf = %d",a);
	printf("\n-------------------------\n");
	b = printf("|%4d|", -12);
	printf("\nprintf = %d",b);
}


