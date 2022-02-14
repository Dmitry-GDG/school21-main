#### • You are asked to do something that is normally banned by the Norm, that will be the only time we autorize it.
#### • Create a macro ABS which replaces its argument by it absolute value :
```
          #define ABS(Value)
```
#### HowTo:
```

```
--------  
#### Test:
Check
```
~~norminette -R CheckForbiddenSourceHeader ~~
```
Create a main.c file:
```
#include "ft_abs.h"
#include <stdio.h>
int	main(void)
{
	printf("ABS of 5 is %d\n", ABS(5));
	printf("ABS of 0 is %d\n", ABS(0));
	printf("ABS of -5 is %d\n", ABS(-5));
	return (0);
}
```
and call it:
```
gcc -Wall -Wextra -Werror main.c && ./a.out
```
#### Output:
```
ABS of 5 is 5
ABS of 0 is 0
ABS of -5 is 5
```