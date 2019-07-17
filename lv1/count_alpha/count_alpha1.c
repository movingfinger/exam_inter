#include <stdio.h>

#define TO_LOWER(c) ((c >= 'A' && c <= 'Z') ? (c) : (c + ('a' - 'A')))
#define IS_ALPHA(c) ((c >= 'a' && c <= 'z') ? 1 : 0)

void	count_alpha(char *s)
{
	int		check[130] = {0};
	int		first = 1;
	int		i = 0;

	while (s[i])
	{
		TO_LOWER(s[i]);
		printf("%c\n", s[i]);
		if (IS_ALPHA(s[i]))
			check[(int)(TO_LOWER(s[i]))]++;
		i++;
	}
	for (int j = 0; s[j]; j++)
	{
		printf("%c\n", s[j]);
		if (check[(int)s[j]])
		{
			if (first)
			{
				first = 0;
				printf("%d%c", check[(int)s[j]], s[j]);
			}
			else
				printf(", %d%c", check[(int)s[j]], s[j]);
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	printf("\n");
	return (0);
}
