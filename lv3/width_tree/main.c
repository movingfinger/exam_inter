#include <stdio.h>
#include "width_tree.h"

#define NODE(v, l, r) &(struct s_node){v, l, r}

void	print_tree(struct s_node *node)
{
	if (!node)
		return;
	print_tree(node->left);
	printf("%d, ", node->value);
	print_tree(node->right);
}

int	main(void)
{
	struct s_node *root = NODE(
		1,
		NODE(
			2,
			NODE(
				4,
				NODE(
					5,
					NODE(8, 0, 0),
					0
					),
				NODE(6, 0, 0)
				),
			NODE(7,
				NODE(
					9,
					NODE(11, 0, 0),
					NODE(12, 0, 0)
					),
				NODE(
					10,
					0,
					NODE(13, 0, 0)
					)
				)
			),
		NODE(3, 0, 0)
		);

//	struct s_node *root = NODE(1, 0, 0);

	print_tree(root);
	printf("\n");
	printf("%d\n", width_tree(root));
}
