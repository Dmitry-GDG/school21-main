#### • Create a function that takes a pointer to int as a parameter, and sets the value "42" to that int.
#### • Here’s how it should be prototyped :
```
          void ft_ft(int *nbr);
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
add at the end of the file:
```
#include <stdio.h>
void	ft_ft(int *nbr);
int	main(void)
{
	int	nbr;
	nbr = 425;
	printf("nbr = %d\n", nbr);
	ft_ft(&nbr);
	printf("after ft_ft nbr = %d\n", nbr);
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_ft.c && ./a.out
```
#### Output:
```
nbr = 425
after ft_ft nbr = 42
```