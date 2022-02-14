#### • Create a function that displays a string of characters on the standard output. 
#### • Here’s how it should be prototyped :
```
          void ft_putstr(char *str);
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
int	main(int argc, char **argv)
{
	(void) argc;
	ft_putstr(argv[1]);
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_putstr.c ft_putchar.c && ./a.out "School 21"
```
#### Output:
```
School 21%  
```