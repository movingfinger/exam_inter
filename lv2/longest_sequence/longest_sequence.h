#ifndef LONGEST_SEQUENCE_H
# define LONGEST_SEQUENCE_H

struct	s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node);

#endif
