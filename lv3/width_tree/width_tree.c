struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	max(int a, int b)
{
	return(a > b ? a : b);
}

int	recur(struct s_node *n, int *max_width)
{
	if (!n)
		return (0);

	int left = recur(n->left, max_width);
	int right = recur(n->right, max_width);
	int local_len = 1 + max(left, right);
	int local_width = 1 + left + right;

	if (local_width > *max_width)
		*max_width = local_width;

	return (local_len);
}

int	width_tree(struct s_node *n)
{
	int max_width = 0;
	recur(n, &max_width);
	return (max_width);
}
