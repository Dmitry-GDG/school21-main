#### • Create a program called ft_display_file that displays, on the standard output, only the content of the file given as argument.
#### • The submission directory should have a Makefile with the following rules : all, clean, fclean. The binary will be called ft_display_file.
#### • The malloc function is forbidden. You can only do this exercise by declaring a fixed-sized array.
#### • All files given as arguments will be valid.
#### • Error messages have to be displayed on their reserved output.
```
$> ./ft_display_file
File name missing.
$> ./ft_display_file Makefile
*content of file Makefile*
$> ./ft_display_file Makefile display_file.c
Too many arguments.
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
Create text.txt file:
```
Any text (bla-bla-bla)
```
and call it:
```
make
make clean
./ft_display_file test.txt
./ft_display_file test.txt "hhh"
./ft_display_file
./ft_display_file "hhh"
./ft_display_file srcs
make fclean
make all
make re
make fclean
```
#### Output:
```
Any text (bla-bla-bla)
```