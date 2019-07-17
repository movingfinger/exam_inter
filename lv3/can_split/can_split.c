struct	s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		count_nodes(struct s_node *n, int *half_tree_size, int *answer_found)
{
	if (n == 0 || *answer_found == 1)
		return (0);

	int		local_size = 1 + count_nodes(n->left, half_tree_size, answer_found) \
						 + count_nodes(n->right, half_tree_size, answer_found);
	if (local_size == *half_tree_size)
		*answer_found = 1;
	return (local_size);
}

int		can_split(struct s_node *n)
{
	int		tree_size = -1;
	int		answer_found = 0;
	tree_size = count_nodes(n, &tree_size, &answer_found);
	if (tree_size % 2 == 1)
		return (0);
	
	tree_size /= 2;
	count_nodes(n, &tree_size, &answer_found);

	return (answer_found);
}
