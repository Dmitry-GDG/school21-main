#include "get_next_line.h"

int get_next_line(char **line)
{
	char tmp[100000];
	int res;
	char buf;
	int i = 0;

	while ((res = read(0, &buf, 1)) > 0 && buf != '\n')
	{
		tmp[i] = buf;
		i++;
	}
	tmp[i] = '\0';
	(*line) = malloc(i + 1);
	i = 0;
	while (tmp[i] != '\0')
	{
		(*line)[i] = tmp[i];
		i++;
	}
	(*line)[i] = '\0';
	return (res);
}

#include <stdio.h>
int main(void)
{
	char *line;
	int res = 1;

	while ((res = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}