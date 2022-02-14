#### • Reproduce the behavior of the function strlen (man strlen). 
#### • Here’s how it should be prototyped :
```
          int ft_strlen(char *str);
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
int	main(int argc, char **argv)
{
	(void) argc;
	printf("Strlen of %s = %d\n", argv[1], ft_strlen(argv[1]));
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_strlen.c && ./a.out "School21"
```
#### Output:
```
Strlen of School21 = 8
```