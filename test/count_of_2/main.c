#include <stdio.h>
#include <stdlib.h>

int    count_of_2(int n);

int		main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", count_of_2(atoi(av[1])));
	return (0);
}
