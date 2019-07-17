#include <unistd.h>
#include <stdlib.h>

#define IS_SPACE(c) ((c == ' ' )|| (c >= '\t' && c <= '\n'))
#define TO_LOWER(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)

int		ft_strlen(char *s)
{
	int		i = -1;
	while (s[++i]);
	return (i);
}

void	swap_words(char **a, char **b)
{
	char *swap = *a;
	*a = *b;
	*b = swap;
}

int		compare_words(char *a, char *b)
{
	int		len_a = ft_strlen(a);
	int		len_b = ft_strlen(b);
	if (len_a != len_b)
		return (len_a - len_b);

	int		i = 0;
	while (i < len_a && TO_LOWER(a[i]) == TO_LOWER(b[i]))
		++i;
	return (TO_LOWER(a[i]) - TO_LOWER(b[i]));
}

void	sort_words(char **words)
{
	int		i;
	int		swapped = 1;

	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (words[++i] != 0)
		{
			if (compare_words(words[i - 1], words[i]) > 0)
			{
				swap_words(&words[i - 1], &words[i]);
				swapped = 1;
			}
		}
	}
}

void	ft_putstr(char *s)
{
	int		i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int		words_count(char *s)
{
	int		n = 0;
	int		i = 0;
	while (s[i])
	{
		while (s[i] && IS_SPACE(s[i]))
			i++;
		if (s[i] && !IS_SPACE(s[i]))
		{
			n++;
			while (s[i] && !IS_SPACE(s[i]))
				i++;
		}
	}
	return (n);
}

char	**ft_split(char *str)
{
	int		size = words_count(str);
	int		i = 0;
	int		j = 0;
	int		len;
	char	**res = (char **)malloc(sizeof(char *) * (size + 1));

	while (str[i])
	{
		while (str[i] && IS_SPACE(str[i]))
			i++;
		len = 0;
		if (str[i] && !IS_SPACE(str[i]))
		{
			while (str[i] && !IS_SPACE(str[i]))
			{
				len++;
				i++;
			}
		}
		res[j] = (char *)malloc(sizeof(char) * (len + 1));
		for (int k = 0; k < len; k++)
			res[j][k] = str[i - len + k];
		res[j++][len] = '\0';
	}
	return (res);
}

void	printf_words(char **words)
{
	int		i = -1;
	int		len = (words[0]) ? ft_strlen(words[0]) : 0;
	int		cur_len;

	while (words[++i] != 0)
	{
		cur_len = ft_strlen(words[i]);
		if (i != 0)
		{
			if (cur_len == len)
				ft_putstr(" ");
			else
			{
				len = cur_len;
				ft_putstr("\n");
			}
		}
		ft_putstr(words[i]);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		char **words = ft_split(av[1]);
		if (words[0])
			sort_words(words);
		printf_words(words);
		free(words);
	}

	write(1, "\n", 1);
	return (0);
}
