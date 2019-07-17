#include <stdio.h>

int		is_anagram(char *a, char *b);

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", is_anagram(av[1], av[2]));
	return (0);
}
