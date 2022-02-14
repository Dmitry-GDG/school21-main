#include <unistd.h>

int main(int argc, char **argv)
{
	int bb[256];
	int i = 0;

	while (i++ < 256)
		bb[i] = 0;
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (bb[(unsigned char)argv[1][i]] == 0)
			{
				bb[(unsigned char)argv[1][i]] = 1;
				write (1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			if (bb[(unsigned char)argv[2][i]] == 0)
			{
				bb[(unsigned char)argv[2][i]] = 1;
				write (1, &argv[2][i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}