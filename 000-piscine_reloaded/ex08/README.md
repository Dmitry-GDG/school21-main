#### • Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’.
#### • Here’s how it should be prototyped :
```
          void ft_is_negative(int n);
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
include <stdio.h>
void	my_print_combo(int i)
{
	printf("If %d?  -  ", i);
	fflush(stdout); //printf() печатает данные в файловом потоке, где его точки 
	// и по умолчанию это stdout stream, а stdout stream буферизован по строке, 
	// т. е. вам нужно очистить буфер, вызвав fflush(stdout)
}
int	main(void)
{
	int	i;
	i = 6;
	my_print_combo(i);
	ft_is_negative(i);
	write(1, "\n", 1);
	i = 0;
	my_print_combo(i);
	ft_is_negative(i);
	write(1, "\n", 1);
	i = -6;
	my_print_combo(i);
	ft_is_negative(i);
	write(1, "\n", 1);
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_is_negative.c ft_putchar.c && ./a.out 
```
#### Output:
```
If 6?  -  P
If 0?  -  P
If -6?  -  N
```