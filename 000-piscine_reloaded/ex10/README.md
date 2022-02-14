#### • Create a function that swaps the value of two integers whose addresses are entered as parameters.
#### • Here’s how it should be prototyped :
```
        void	ft_swap(int *a, int *b);
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
void	ft_swap(int *a, int *b);
int	main(void)
{
	int	a, b;
	a = 21;
	b = 42;
	printf("a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("after ft_swap a = %d, b = %d\n", a, b);
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_swap.c && ./a.out
```
#### Output:
```
a = 21, b = 42
after ft_swap a = 42, b = 21
```