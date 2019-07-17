#include <stdio.h>

int		ab_comb(int a, int b)
{
	return (a * 10 + b);
}

int		ca_comb(int a, int c)
{
	return (c * 10 + a);
}

void    equation(int n)
{
	for (int a = 0; a < 10; a++)
		for (int b = 0; b < 10; b++)
			for(int c = 0; c < 10; c++)
				if (n == (ab_comb(a, b) + ca_comb(a, c)))
					printf("A = %d, B = %d, C = %d\n", a, b, c);
}
