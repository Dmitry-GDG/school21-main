#### • Create the function ft_foreach which, for a given ints array, applies a function on all elements of the array. This function will be applied following the array’s order.
#### • Here’s how the function should be prototyped :
```
          void ft_foreach(int *tab, int length, void(*f)(int));
```
#### • For example, the function ft_foreach could be called as follows in order to display all ints of the array :
```
          ft_foreach(tab, 1337, &ft_putnbr);
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
create ft_putnbr.c file:
```
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= (-1);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
```
add at the end of the ft_foreach.c file::
```
void	ft_foreach(int *tab, int length, void(*f)(int));
void	ft_putnbr(int nbr);
int	main(void)
{
	int	i;
	int	tab[1500];

	i = 0;
	while (i < 1500)
	{
		tab[i] = i;
		i++;
	}
	ft_foreach(tab, 13, &ft_putnbr);
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_foreach.c ft_putnbr.c && ./a.out
```
#### Output:
```
0123456789101112%  
```