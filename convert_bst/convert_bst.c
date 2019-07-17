struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *leftmost(struct s_node *cur)
{
	while (cur->left)
		cur = cur->left;
	return (cur);
}

struct s_node *rightmost(struct s_node *cur)
{
	while (cur->right)
		cur = cur->right;
	return (cur);
}

void	convert_subtree(struct s_node *cur, struct s_node **prev)
{
	if (cur == 0)
		return ;
	convert_subtree(cur->left, prev);
	if (*prev)
	{
		(*prev)->right = cur;
		cur->left = *prev;
	}
	*prev = cur;
	convert_subtree(cur->right, prev);
}

struct 	s_node *convert_bst(struct s_node *bst)
{
	if (bst == 0)
		return (0);
	
	struct s_node *prev = 0;
	convert_subtree(bst, &prev);

	struct s_node *min = leftmost(bst);
	min->left = rightmost(bst);
	min->left->right = min;
	return (min);
}
