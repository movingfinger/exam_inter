#ifndef WIDTH_TREE_H
# define WIDTH_TREE_H

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};
int	max(int a, int b);
int	recur(struct s_node *n, int *max_width);
int	width_tree(struct s_node *n);

#endif
