#### • Create the Makefile that’ll compile your libft.a.
#### • The Makefile will get its source files from the "srcs" directory.
#### • The Makefile will get its header files from the "includes" directory.
#### • The lib will be at the root of the exercise.
#### • The Makefile should also implement the following rules: clean, fclean and re as well as all.
#### • fclean does the equivalent of a make clean and also erases the binary created during the make. re does the equivalent of a make fclean followed by a make.
#### • We’ll only fetch your Makefile and test it with our files. For this exercise, only the  following 5 mandatory functions of your lib have to be handled : (ft_putchar, ft_putstr, ft_strcmp, ft_strlen and ft_swap).
### • Watch out for wildcards!
```
gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
ranlib libft.a;
rm *.o;       
```
#### HowTo:
```
Для того чтобы make не искал файлы с именами целей, их следует определить в Makefile при помощи директивы .PHONY:  
	.PHONY:		all clean fclean re  
Существует негласное правило, согласно которому следует именовать переменные в верхнем регистре, например:  
	SRC := main.c hello.c  
Где символ ':=' создает переменную SRC и присваивает ей значение "main.c hello.c".  
Так мы определили список исходных файлов. Для использования значения переменной ее следует разименовать при помощи конструкции $(<VAR_NAME>), например так:  
	gcc -o hello $(SRC)  
Make-файл содержит «правила» в следующей форме:  
	target: dependencies  
    	system command(s)  
*target - обычно является имя файла, который генерируется программой; примеры целей — исполняемые или объектные файлы. Цель может также являться именем действия, которое необходимо выполнить, например, «clean».

*dependencies (также называется предварительным условием) — это файл, используемый в качестве входных данных для создания цели. Цель часто зависит от нескольких файлов. Однако, правило, указывающее способ для цели, не должно иметь любых предварительных условий. Например, правило, содержащее команду delete («удалить»), связано с целью clean («очистить»), не имеющей предварительного условия.

*system command(s) (также называемая способом) — это действие, которое выполняет утилита make. Способ может содержать более одной команды, либо в той же строке или каждая в своей строке. Обратите внимание, что строка с командой должна начинаться с табуляции! 

$@ is the name of the target being generated, and $< the first prerequisite (usually a source file). You can find a list of all these special variables in the GNU Make manual.  

For example, consider the following declaration:  

	all: library.cpp main.cpp  
In this case:  

$@ evaluates to all  
$< evaluates to library.cpp  
$^ evaluates to library.cpp main.cpp
```
--------  
```  
OBJECTS=main.o hello.o factorial.o  

hello: $(OBJECTS)  
    g++ -o hello $(OBJECTS)

main.o: main.c  
    g++ -c main.c  

hello.o: hello.c  
    g++ -c hello.c  

factorial.o: factorial.c  
    g++ -c factorial.c
```  
pro: fixes efficiency issue  
con: new maintenance nightmare, potential typo on object files rules  
To improve on this, we can replace all object file rules with a single .c.o rule:  
```  
OBJECTS=main.o hello.o factorial.o  

hello: $(OBJECTS)  
    g++ -o hello $(OBJECTS)  

.c.o:  
    g++ -c $< -o $@
```  
pro: back to having a short makefile, somewhat easy to read  
Here the .c.o rule defines how to build anyfile.o from anyfile.c.  

$< matches to first dependency, in this case, anyfile.c  
$@ matches the target, in this case, anyfile.o.  

--------  
#### Test:
Check
```
norminette -R CheckForbiddenSourceHeader 
```
and call it:
```
make
make clean
make all
make re
make fclean
```
#### Output:
```
gcc -Wall -Wextra -Werror -c srcs/ft_putchar.c -o srcs/ft_putchar.o -I includes/ft.h
gcc -Wall -Wextra -Werror -c srcs/ft_putstr.c -o srcs/ft_putstr.o -I includes/ft.h
gcc -Wall -Wextra -Werror -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o -I includes/ft.h
gcc -Wall -Wextra -Werror -c srcs/ft_strlen.c -o srcs/ft_strlen.o -I includes/ft.h
gcc -Wall -Wextra -Werror -c srcs/ft_swap.c -o srcs/ft_swap.o -I includes/ft.h
ar rc libft.a ./srcs/ft_putchar.o ./srcs/ft_putstr.o ./srcs/ft_strcmp.o ./srcs/ft_strlen.o ./srcs/ft_swap.o
ranlib libft.a
```