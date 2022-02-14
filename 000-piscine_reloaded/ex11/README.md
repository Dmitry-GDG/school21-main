#### • This function divides parameters a by b and stores the result in the int pointed by div. It also stores the remainder of the division of a by b in the int pointed by mod.
#### • Create a function ft_div_mod prototyped like this :
```
          void ft_div_mod(int a, int b, int *div, int *mod);
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
int	main(void)
{
	int	a, b, div, mod;
	a = 100;
	b = 42;
	ft_div_mod(a, b, &div, &mod);
	printf("a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_div_mod.c && ./a.out
```
#### Output:
```
a = 100, b = 42, div = 2, mod = 16
```