#include <stdlib.h>
#include <stdio.h>

int find_pivot(int *arr, int n);

int		main(int ac, char **av)
{
	int		*n;
	int		res = 0;
	int		size;

	if (ac > 1)
	{
		size = ac - 1;
		n = (int *)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++)
		{
			n[i] = atoi(av[i + 1]);
			printf("%d ", n[i]);
		}
		printf("\n");
		res = find_pivot(n, size);
		printf("%d\n", res);
	}
	return (0);
}
