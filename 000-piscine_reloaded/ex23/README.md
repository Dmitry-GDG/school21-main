#### • Create a file ft_point.h that’ll compile the following main :
```
#include "ft_point.h"
void set_point(t_point *point) 
{
  point->x = 42;
  point->y = 21;
}
int main(void) 
{
  t_point   point;
  set_point(&point);
return (0); 
}
```
#### HowTo:
```

```
--------  
#### Test:
Check
```
norminette -R CheckForbiddenSourceHeader 
```
Create a main.c file:
```
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
```
and call it:
```
cc -Wall -Wextra -Werror main.c && ./a.out
```
#### Output:
```
at address 0x7ffee7a73760 is placed 42
at address 0x7ffee7a73764 is placed 21
```