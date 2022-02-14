#### • Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.
#### • If there’s an error, the function should return 0.
#### • Your function must return its result in less than two seconds.
#### • Here’s how it should be prototyped :
```
          int ft_iterative_factorial(int nb);
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
	printf("Iterative factorial of -1 is %d\n", ft_iterative_factorial(-1));
	printf("Iterative factorial of 0 is %d\n", ft_iterative_factorial(0));
	printf("Iterative factorial of 5 is %d\n", ft_iterative_factorial(5));
	printf("Iterative factorial of 12 is %d\n", ft_iterative_factorial(12));
	printf("Iterative factorial of 13 is %d\n", ft_iterative_factorial(13));
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_iterative_factorial.c && ./a.out
```
#### Output:
```
Iterative factorial of -1 is 0
Iterative factorial of 0 is 1
Iterative factorial of 5 is 120
Iterative factorial of 12 is 479001600
Iterative factorial of 13 is 0
```