#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     n;
    int     fd;
    char    *str;

    (void)argc;
    str = NULL;
    n = 1;
    fd = open(argv[1], O_RDONLY);
    printf("fd is : %d\n", fd);
    while (n == 1)
    {
        n = get_next_line(fd, &str);
        printf("\033[1;31m"); 
        printf("\t\t\t%s\n", str);
        printf("\033[0m");
        free(str);
    }
    if (n == 1)
        printf("\nOK");
    if (n == 0)
        printf("\nFINISH");
    else
        printf("\nERROR");
}

/*
A GERER :
- Mauvais file descriptor (fd = -1);
- **Line mauvais ;
- BUFFER_SIZE valeurs chelou ?
*/