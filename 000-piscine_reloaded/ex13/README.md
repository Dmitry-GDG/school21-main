#### • Create a recursive function that returns the factorial of the number given as a parameter.
#### • If there’s an error, the function should return 0. 
#### • Here’s how it should be prototyped :
```
          int ft_recursive_factorial(int nb);
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
	printf("Recirsive factorial of -1 is %d\n", ft_recursive_factorial(-1));
	printf("Recursive factorial of 0 is %d\n", ft_recursive_factorial(0));
	printf("Recirsive factorial of 5 is %d\n", ft_recursive_factorial(5));
	printf("Recursive factorial of 12 is %d\n", ft_recursive_factorial(12));
	printf("Recursive factorial of 13 is %d\n", ft_recursive_factorial(13));
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_recursive_factorial.c && ./a.out
```
#### Output:
```
Recirsive factorial of -1 is 0
Recursive factorial of 0 is 1
Recirsive factorial of 5 is 120
Recursive factorial of 12 is 479001600
Recursive factorial of 13 is 0
```