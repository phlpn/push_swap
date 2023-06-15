#include "push_swap.h"

t_node *create_node(int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->value = value;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return new_node;
}

t_stack *create_stack()
{
	t_stack *new_stack = malloc(sizeof(t_stack));
	if (new_stack)
	{
		new_stack->head = NULL;
		new_stack->tail = NULL;
	}
	return new_stack;
}

t_pushswap *create_pushswap()
{
	t_pushswap *new_pushswap = malloc(sizeof(t_pushswap));
	if (new_pushswap)
	{
		new_pushswap->a_stack = create_stack();
		new_pushswap->b_stack = create_stack();
	}
	return new_pushswap;
}

int	main(int ac, char **av)
{
	// Creating a sample pushswap structure
    t_pushswap *pushswap = create_pushswap();

    // Adding nodes to the a_stack
    t_node *node1 = create_node(10);
    t_node *node2 = create_node(20);
    t_node *node3 = create_node(30);

    pushswap->a_stack->head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->prev = node2;
    node2->prev = node1;
    pushswap->a_stack->tail = node3;

    // Accessing and printing the values in the a_stack
    printf("Values in a_stack: ");
    t_node *current = pushswap->a_stack->head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    // Freeing allocated memory
    free(node1);
    free(node2);
    free(node3);
    free(pushswap->a_stack);
    free(pushswap->b_stack);
    free(pushswap);

    return 0;
}