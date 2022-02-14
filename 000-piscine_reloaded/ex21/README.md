#### • Create a function ft_range which returns an array of ints. This int array should contain all values between min and max.
#### • Min included - max excluded.
#### • If min's value is greater or equal to max’s value, a null pointer should be returned.
#### • Here’s how it should be prototyped :
```
         int	*ft_range(int min, int max);
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
	int i, a, b;
	int	*result;
	a = 5;
	b = 12;
	printf("ft_range of %d and %d is\n", a, b);
	result = ft_range(a, b);
	i = 0;
	while (result[i])
	{
		printf("integer %d\tis placed in address %p\n", result[i], &result[i]);
		i++;
	}
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_range.c && ./a.out
```
#### Output:
```
ft_range of 5 and 12 is
integer 5       is placed in address 0x7fe339504080
integer 6       is placed in address 0x7fe339504084
integer 7       is placed in address 0x7fe339504088
integer 8       is placed in address 0x7fe33950408c
integer 9       is placed in address 0x7fe339504090
integer 10      is placed in address 0x7fe339504094
integer 11      is placed in address 0x7fe339504098
```