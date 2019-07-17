#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int		i = 0;
	int		j = 0;
	int		begin = 0;

	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (begin > 0)
				printf(" ");
			printf("%d", a[i]);
			begin++;
			i++;
			j++;
		}
		else if (a[i] > b[j])
		{
			j++;
		}
		else
			i++;
	}
	printf("\n");
}
