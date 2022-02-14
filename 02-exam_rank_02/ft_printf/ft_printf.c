#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

static void my_putnbr(unsigned long dd, unsigned int base)
{
	if (dd > base - 1)
	{
		my_putnbr(dd / base, base);
		my_putnbr(dd % base, base);
	}
	else
	{
		if (dd > 9)
			dd += 'a' - 10;
		else
			dd += '0';
		write (1, &dd, 1);
	}
}

int ft_printf(const char *fmt, ... )
{
	va_list ap;
	int i = 0;
	int f_minus;
	int f_width;
	int f_acc;
	int outp = 0;
	int len;
	int j;
	char *s;
	long d;
	unsigned long dd;
	unsigned long x;

	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			f_minus = 0;
			f_width = 0;
			f_acc = -1;
			i++;
			while (fmt[i] >= '0' && fmt[i] <= '9')
			{
				f_width = f_width * 10 + fmt[i] - '0';
				i++;
			}
			if (fmt[i] == '.')
			{
				f_acc = 0;
				i++;
				while (fmt[i] >= '0' && fmt[i] <= '9')
				{
					f_acc = f_acc * 10 + fmt[i] - '0';
					i++;
				}
			}
			if (fmt[i] == 's')
			{
				s = va_arg(ap, char *);
				len = 0;
				while (s[len] != '\0')
					len++;
				if (f_acc != -1 && f_acc < len)
					len = f_acc;
				while (f_width-- > len)
					outp += write (1, " ", 1);
				j = 0;
				while (j < len && s[j] != '\0')
				{
					outp += write (1, &s[j], 1);
					j++;
				}
			}
			else if (fmt[i] == 'd')
			{
				d = va_arg(ap, int);
				d *= 1;
				if (d < 0)
				{
					f_minus = 1;
					f_width--;
					d *= (-1);
				}
				dd = d;
				len = 1;
				while (dd / 10 > 0)
				{
					len++;
					dd /= 10;
				}
				while (f_width > len && f_width > f_acc)
				{
					outp += write (1, " ", 1);
					f_width--;
				}
				if (f_minus == 1)
					outp += write (1, "-", 1);
				while (f_acc-- > len)
					outp += write(1, "0", 1);
				my_putnbr(d, 10);
				outp += len;
			}
			else if (fmt[i] == 'x')
			{
				x = va_arg(ap, unsigned long);
				dd = x;
				len = 1;
				while (dd / 16 > 0)
				{
					len++;
					dd /= 16;
				}
				while (f_width > len && f_width > f_acc)
				{
					outp += write (1, " ", 1);
					f_width--;
				}
				while (f_acc-- > len)
					outp += write(1, "0", 1);
				my_putnbr(x, 16);
				outp += len;
			}
			else
				outp *= write (1, &fmt[i], 1);
		}
		else
		{
			outp += write(1, &fmt[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (outp);
}

#include <stdio.h>
int main(void)
{
ft_printf("%10.2s\n", "toto");
printf("%10.2s\n", "toto");
printf("\n");
ft_printf("Magic %s is %5d", "number", 16);
printf("\n");
printf("Magic %s is %5d", "number", 16);
printf("\n");
printf("\n");
ft_printf("Hexadecimal for %d is %20.12x\n", 42, 15);	
printf("Hexadecimal for %d is %20.12x\n", 42, 15);
}