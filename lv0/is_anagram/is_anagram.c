int		is_anagram(char *a, char *b)
{
	char	check[130] = {0};
	for (int i = 0; a[i]; i++)
		check[(int)a[i]]++;
	for (int j = 0; b[j]; j++)
		check[(int)b[j]]--;
	for (int k = 0; k < 130; k++)
		if (check[k] != 0)
			return (0);
	return (1);
}
