struct	s_node {
	void *content;
	struct s_node *next;
};

int		find_match(struct s_node *needle, struct s_node *haystack)
{
	while (haystack)
	{
		if (needle == haystack)
			return (1);
		haystack = haystack->next;
	}
	return (0);
}

void	*intersection(struct s_node *lst1, struct s_node *lst2)
{
	while (lst1)
	{
		if (find_match(lst1, lst2))
			return (lst1);
		lst1 = lst1->next;
	}
	return (0);
}
