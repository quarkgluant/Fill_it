#include <stdio.h>

char *ft_itoa(int n);

int 	main (void)
{
	printf("itoa %s\n", ft_itoa(45));
	printf("itoa %s\n", ft_itoa(-2147483648));
	printf("itoa %s\n", ft_itoa(2147483647));
	return (0);
}
