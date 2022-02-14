#### • Reproduce the behavior of the function strdup (man strdup). 
#### • Here’s how it should be prototyped :
```
        char *ft_strdup(char *src);  
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
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("strdup of %s is %s\n", argv[1], strdup(argv[1]));
		printf("ft_strdup of %s is %s\n", argv[1], ft_strdup(argv[1]));
		return (0);
	}
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_strdup.c && ./a.out "School 21"
```
#### Output:
```
strdup of School 21 is School 21
ft_strdup of School 21 is School 21
```