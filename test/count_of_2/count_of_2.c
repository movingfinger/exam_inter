int		is_any_2(int n)
{
	int		count = 0;
	while (n > 0)
	{
		if ((n % 10 == 2))
			count++;
		n /= 10;
	}
	return (count);
}

int		count_of_2(int n)
{
	int		count = 0;

	for (int i = 1; i <= n; i++)
		count += is_any_2(i);
	return (count);
}
