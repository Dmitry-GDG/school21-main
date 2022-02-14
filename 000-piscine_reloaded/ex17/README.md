#### • Reproduce the behavior of the function strcmp (man strcmp). 
#### • Here’s how it should be prototyped :
```
          int ft_strcmp(char *s1, char *s2);
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
#include <string.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("strcmp of %s and %s is %d\n", argv[1], argv[2], strcmp(argv[1], argv[2]));
		printf("ft_strcmp of %s and %s is %d\n", argv[1], argv[2], ft_strcmp(argv[1], argv[2]));
		return (0);
	}
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_strcmp.c && ./a.out "asdfr" "asdfc"
```
#### Output:
```
strcmp of asdfr and asdfc is 15
ft_strcmp of asdfr and asdfc is 15
```