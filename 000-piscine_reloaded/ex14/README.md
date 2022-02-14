#### • Create a function that returns the square root of a number (if it exists), or 0 if the square root is an irrational number.
#### • Your function must return its result in less than two seconds.
#### • Here’s how it should be prototyped :
```
          int ft_sqrt(int nb);
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
	printf("Square root of -1 is %d\n", ft_sqrt(-1));
	printf("Square root of 0 is %d\n", ft_sqrt(0));
	printf("Square root of 16 is %d\n", ft_sqrt(16));
	printf("Square root of 225 is %d\n", ft_sqrt(225));
	printf("Square root of 255 is %d\n", ft_sqrt(255));
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_sqrt.c && ./a.out
```
#### Output:
```
Square root of -1 is 0
Square root of 0 is 0
Square root of 16 is 4
Square root of 225 is 15
Square root of 255 is 0
```