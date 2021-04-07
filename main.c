#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int b;

	int *p;

	a = ft_printf("|%16.p|", p);
	ft_printf("\nft_printf = %d",a);
	printf("\n-------------------------\n");
	b = printf("|%16.p|", p);
	printf("\nprintf = %d",b);
}


