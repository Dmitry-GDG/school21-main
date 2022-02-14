#include "ft_abs.h"
#include <stdio.h>
int	main(void)
{
	printf("ABS of 5 is %d\n", ABS(5));
	printf("ABS of 0 is %d\n", ABS(0));
	printf("ABS of -5 is %d\n", ABS(-5));
	return (0);
}
/* call it:
* gcc -Wall -Wextra -Werror main.c && ./a.out */