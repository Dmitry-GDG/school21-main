#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	printf("at address %p is placed %d\n", &point.x, point.x);
	printf("at address %p is placed %d\n", &point.y, point.y);
	return (0);
}
/* Call it:
* gcc -Wall -Wextra -Werror main.c && ./a.out */