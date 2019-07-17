int is_anagram(char *a, char *b)
{
	int		tmp[130] = {0};

	for (int i = 0; a[i]; i++)
		tmp[(int)a[i]]++;
	for (int j = 0; b[j]; j++)
		tmp[(int)b[j]]--;
	for (int k = 0; b[k]; k++)
		if (tmp[(int)b[k]] != 0)
			return (0);
	return (1);
}
