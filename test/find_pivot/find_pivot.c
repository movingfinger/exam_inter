#include <stdio.h>

int find_pivot(int *arr, int n)
{
	int		a = 0;
	int		b = 0;

	for (int i = n - 1; i > 0; --i)
		b += arr[i];
	for (int j = 0; j < n - 1; j++)
	{
		a += arr[j];
		b -= arr[j + 1];
		if (a == b)
			return(j + 1);
	}
	return (-1);
}
