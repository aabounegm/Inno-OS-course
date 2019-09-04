#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int value;
	struct node *next;
};

void print_list(struct node *head)
{
	printf("{ ");
	while(head != NULL)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("}\n");
}

void insert_node(struct node *after, struct node *new_node)
{
	struct node *next = after->next;
	after->next = new_node;
	new_node->next = next;
}

void delete_node(struct node *head, struct node *to_delete)
{
	struct node *prev, *next;
	// find previous node
	while(head->next != to_delete)
		head = head->next;
	prev = head;
	next = to_delete->next;
	
	prev->next = next;
	to_delete->next = NULL;
	free(to_delete);
}

int main()
{
	struct node *head = malloc(sizeof(struct node));
	head->value = 0;
	struct node *current, *prev = head;
	for(int i=1; i<10; i++)
	{
		current = malloc(sizeof(struct node));
		current->value = i;
		prev->next = current;
		current->next = NULL;
		prev = current;
	}
	print_list(head);
	
	struct node *new_node = malloc(sizeof(struct node));
	new_node->value = 20;
	insert_node(head, new_node);
	print_list(head);
	
	delete_node(head, head->next->next->next);
	print_list(head);
	
	
	current = head;
	while(current != NULL)
	{
		struct node *temp = current;
		current = current->next;
		temp->next = NULL;
		free(temp);
	}
	head = NULL;
	
	print_list(head);
	
	return 0;
}