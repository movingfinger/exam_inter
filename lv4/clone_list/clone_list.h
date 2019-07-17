#ifndef CLONE_LIST_H
# define CLONE_LIST_H

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};
struct s_node	*create_node(int data);
int				find_node_index(struct s_node *needle, struct s_node *haystack);
struct s_node	*get_node_by_index(int index, struct s_node *haystack);
struct s_node	*clone_list(struct s_node *node);

#endif
