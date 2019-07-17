#include <stdio.h>
#include "stack.h"

int 	main(void)
{
	char a[] = "aaaaa";			(void)a;
	char b[] = "bbbbb";			(void)b;
	char c[] = "ccccc";			(void)c;
	char d[] = "dddddicks";		(void)d;
	struct s_stack *stack;

	stack = init(); 			(void)stack;
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	push(stack, a); push(stack, b); push(stack, c); push(stack, d);
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("isEmpty: %d\n", isEmpty(stack));

	return (0);
}
