#### • Create a function that displays all digits, on a single line, by ascending order. 
#### • Here’s how it should be prototyped :
```
         void ft_print_numbers(void);
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
int	main(void)
{
	ft_print_numbers();
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_print_numbers.c ft_putchar.c && ./a.out 
```
#### Output:
```
0123456789%   
```