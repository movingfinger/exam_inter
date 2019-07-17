#include <stdio.h>

int		words_count(char *s);
char	**ft_split(char *str);

int		main(int ac, char **av)
{
	int		count = 0;
	char	**res;
	if (ac == 2)
	{
		count = words_count(av[1]);
		res = ft_split(av[1]);
		for (int i = 0 ; i < count; i++)
			printf("%s\n", res[i]);
	}
	return (0);
}
