#### • Create a function ft_count_if which will return the number of elements of the array that return 1, passed to the function f.
#### • The array will be delimited by 0.
#### • Here’s how the function should be prototyped :
```
          int ft_count_if(char **tab, int(*f)(char*));
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
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("result of ft_count_if is: %d\n", ft_count_if(argv, ft_strlen));
	}
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_count_if.c && ./a.out gtr JJ iou yhgfd JJ j KI k g JJJ
```
#### Output:
```
result of ft_count_if is: 3
```