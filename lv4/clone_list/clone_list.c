#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node	*create_node(int data)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->data = data;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

int				find_node_index(struct s_node *needle, struct s_node *haystack)
{
	int i = 0;

	while (haystack)
	{
		if (needle == haystack)
			return (i);
		++i;
		haystack = haystack->next;
	}
	return (-1);
}

struct s_node	*get_node_by_index(int index, struct s_node *haystack)
{
	int i = 0;

	while (i < index)
	{
		++i;
		haystack = haystack->next;
	}
	return (haystack);
}

struct s_node	*clone_list(struct s_node *node)
{
	if (node == NULL)
		return (NULL);

	struct s_node *head = node;
	struct s_node *new_head = create_node(head->data);
	struct s_node *new_cur = new_head;
	node = node->next;
	while (node)
	{
		new_cur->next = create_node(node->data);
		new_cur = new_cur->next;
		node = node->next;
	}

	node = head;
	new_cur = new_head;
	while (node)
	{
		if (node->other != NULL)
			new_cur->other = get_node_by_index(find_node_index(node->other, head), new_head);
		new_cur = new_cur->next;
		node = node->next;
	}

	return (new_head);
}
