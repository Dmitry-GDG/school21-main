#### • We’re dealing with a program here, you should therefore have a function main in your .c file.
#### • Create a program that displays its given arguments. 
#### • Example :
```
$>./a.out test1 test2 test3
test1 
test2
test3 
$>
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
and call it:
```
gcc -Wall -Wextra -Werror ft_print_params.c ft_putchar.c && ./a.out test1 test2 test3
```
#### Output:
```
test1
test2
test3
```