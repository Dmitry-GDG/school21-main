#### • Create a function that displays the alphabet in lowercase, on a single line, by ascending order, starting from the letter ’a’.
#### • Here’s how it should be prototyped :
```
         void ft_print_alphabet(void);
```
#### HowTo:
```

```
--------  
#### Test:
add at the end of the file:
```
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror ft_print_alphabet.c ft_putchar.c && ./a.out
```
#### Output:
```
abcdefghijklmnopqrstuvwxyz%  
```