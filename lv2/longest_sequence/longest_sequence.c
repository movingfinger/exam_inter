struct	s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		max_three(int a, int b, int c)
{
	return ((a > b) ? ((a > c) ? a : c) : (b > c) ? b : c);
}

int		recur(struct s_node *node, int *longest_seq)
{
	if (node == 0)
		return (0);
	int		left = recur(node->left, longest_seq);
	int		right = recur(node->right, longest_seq);
	int		continuity = 0;

	if (node->left && node->left->value == node->value + 1)
	{
		left++;
		continuity = 1;
	}
	if (node->right && node->right->value == node->value + 1)
	{
		right++;
		continuity = 1;
	}

	int		local_longest = max_three(1, left, right);
	if (local_longest > *longest_seq)
		*longest_seq = local_longest;
	if (continuity == 1)
		return (local_longest);
	return (1);
}

int	longest_sequence(struct s_node *node)
{
	int		longest_seq = 0;
	recur (node, &longest_seq);
	return (longest_seq);
}
