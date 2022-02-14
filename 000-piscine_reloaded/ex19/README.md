#### • We’re dealing with a program here, you should therefore have a function main in your .c file.
#### • Create a program that displays its given arguments sorted by ascii order.
#### • It should display all arguments, except for argv[0].
#### • All arguments have to have their own line.
```
         
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
gcc -Wall -Wextra -Werror ft_putchar.c ft_sort_params.c \
&& ./a.out rtfgrc qwe xswtt asdtu
```
#### Output:
```
asdtu
qwe
rfvfhfdffa
xswtt
```