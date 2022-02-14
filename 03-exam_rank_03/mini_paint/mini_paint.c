#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_zone
{
	int width;
	int height;
	char background;
} t_zone;

typedef struct s_fig
{
	char c;
	float x;
	float y;
	float radius;
	char ch;
} t_fig;

int ft_strlen (char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int my_print_mssg(char *str)
{
	write (1, str, ft_strlen(str));
	return (1);
}

char *my_init_draw(t_zone zona)
{
	char *drawing;
	int i;
	drawing = (char *)malloc(sizeof(char) * (zona.height * zona.width + 1));
	if (!drawing)
		return (NULL);
	i = 0;
	while (i < (zona.height * zona.width))
	{
		drawing[i] = zona.background;
		i++;
	}
	drawing[i] = '\0';
	return(drawing);
}

int my_chck(float x, float y, t_fig fig)
{
	float dist;
	dist = sqrtf(powf((x - fig.x), 2.) + powf ((y - fig.y), 2.));
	if (dist <= fig.radius)
	{
		if ((fig.radius - dist) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void my_fill_draw2(t_zone zona, char *drawing, t_fig fig)
{
	int x;
	int y;
	int res;
	y = 0;
	while (y < zona.height)
	{
		x = 0;
		while (x < zona.width)
		{
			res = my_chck((float) x, (float) y, fig);
			if ((res == 2 && fig.c == 'c') || (res && fig.c == 'C'))
				drawing [y * zona.width + x] = fig.ch;
			x++;
		}
		y++;
	}
}

int my_fill_draw(FILE *file, t_zone zona, char *drawing)
{
	int res;
	t_fig fig;
	while((res = fscanf(file, "%c %f %f %f %c\n", &fig.c, &fig.x, &fig.y, &fig.radius, &fig.ch)) == 5)
	{
		if (fig.radius <= 0.00000000 || ((fig.c != 'c') && (fig.c != 'C')))
			return (0);
		my_fill_draw2(zona, drawing, fig);
	}
	if (res != -1)
		return (0);
	return (1);
}

void my_print_draw(t_zone zona, char *drawing)
{
	int i;
	i = 0;
	while (i < zona.height)
	{
		write(1, drawing + i * zona.width, zona.width);
		write (1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	FILE *file;
	t_zone zona;
	char *drawing;
	if (argc != 2)
		return (my_print_mssg("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (my_print_mssg("Error: Operation file corrupted\n"));
	if (fscanf(file, "%i %i %c\n", &zona.width, &zona.height, &zona.background) != 3)
	{
		fclose (file);
		return (my_print_mssg("Error: Operation file corrupted\n"));
	}
	if (zona.width <= 0 || zona.width > 300 || zona.height <= 0 || zona.height > 300)
	{
		fclose (file);
		return (my_print_mssg("Error: Operation file corrupted\n"));
	}
	if (!(drawing = my_init_draw(zona)))
	{
		fclose (file);
		return (my_print_mssg("Error: Operation file corrupted\n"));
	}
	if (!(my_fill_draw(file, zona, drawing)))
	{
		free(drawing);
		fclose (file);
		return (my_print_mssg("Error: Operation file corrupted\n"));
	}
	my_print_draw(zona, drawing);
	free(drawing);
	fclose (file);
	return (0);
}
