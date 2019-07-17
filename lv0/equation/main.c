#include <stdlib.h>

void    equation(int n);

int		main(int ac, char **av)
{
	if (ac == 2)
		equation(atoi(av[1]));
	return (0);
}
