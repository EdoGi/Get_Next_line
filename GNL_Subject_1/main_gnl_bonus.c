#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int     n;
	int 	count;
	int		i;
	int     *fd;
	char    *str;

	(void)argc;
	str = NULL;
	n = 1;
	i = 1;
	count = 0;
	fd = malloc((argc - 1) * sizeof(int));
	if (!fd)
	{
		printf("Malloc failed\n");
		return (-1);
	}
	while (argv[i])
	{
		fd[count] = open(argv[i], O_RDONLY);
		printf("fd is : %d\n", fd[count]);
		printf("argv %s\n", argv[i]);
		count++;
		i++;
	}
	printf("count %d\n", count);
	while (n == 1)
	{
		i = 0;
		while (i < count)
		{
			n = get_next_line(fd[i], &str);
			printf("\033[1;31m"); 
			printf("\t\t\t%s\n", str);
			printf("\033[0m");
			free(str);
			i++;
		}
	}
	if (n == 0)
		printf("\nFINISH");
	else
		printf("\nERROR");
	return(0);
}
