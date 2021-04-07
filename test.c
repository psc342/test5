#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int b;

	a = ft_printf("|%-*.*u|",4, 0, -8);
	ft_printf("\nft_printf = %d",a);
	printf("\n-------------------------\n");
	b = printf("|%-*.*u|",4, 0, -8);
	printf("\nprintf = %d",b);
}


