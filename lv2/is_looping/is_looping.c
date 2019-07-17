#include <string.h>

struct	s_node
{
	int				value;
	struct s_node 	*next;
};

int		is_looping(struct s_node *node)
{
	if (node == NULL || node->next == NULL)
		return (0);
	struct s_node *slow = node;
	struct s_node *fast = node->next;

	while (fast->next && fast->next->next)
	{
		if (fast == slow)
			return (1);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}
