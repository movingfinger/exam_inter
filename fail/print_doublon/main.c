#include <stdlib.h>
#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb);

int		main(int ac, char **av)
{
	int		size1 = 0;
	int		size2 = 0;
	int		*n1;
	int		*n2;

	if (ac > 1)
	{
		for (int i = 1; av[i][0] != '.'; i++)
			size1++;
		for (int i = size1 + 2; i < ac; i++)
			size2++;
		n1 = (int *)malloc(sizeof(int) * size1);
		n2 = (int *)malloc(sizeof(int) * size2);
		for (int i = 1; av[i][0] != '.'; i++)
			n1[i - 1] = atoi(av[i]);
		for (int i = size1 + 2; i < ac; i++)
			n2[i - size1 - 2] = atoi(av[i]);
		print_doublon(n1, size1, n2, size2);
	}
	return (0);
}
