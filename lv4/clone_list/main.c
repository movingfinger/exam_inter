#include <stdio.h>
#include "clone_list.h"

void	print_list(struct s_node *head)
{
	while (head)
	{
		printf("Node: %p\nData: %d\nOther: %p; ", head, head->data, head->other);
		if (head->other)
			printf("%d", head->other->data);
		printf("\n---\n");
		head = head->next;
	}
}

int		main(void)
{
	struct s_node *head = create_node(5);
	head->next = create_node(10);
	head->next->next = create_node(15);
	head->next->next->next = create_node(20);
	head->next->next->next->next = create_node(25);
	head->next->next->next->next->next = create_node(30);
	head->next->next->next->next->next->other = head->next->next->next->next; //25
	head->next->next->next->next->other = head; //5
	head->next->next->next->other = head->next; //10
	head->next->next->other = head->next->next; //15
	print_list(head);
	printf("\n\n");

	print_list(clone_list(head));
}
