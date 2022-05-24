#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STACK
struct stack{
	struct node_stack *head;
};

struct node_stack{
	struct node_list *first_node;
	struct node_stack *next;
};

//LIST
struct list{
	struct node_list *first_node;
};

struct node_list{
	int num;
	struct node_list *next;
};

void add_num(struct list *organization, int i, int num);
int push(struct stack *the_stack, struct list *organization);
void pop(struct stack *the_stack);

//MAIN
int main(void)
{
	char operation[4], num01, num02[100];
	struct stack *the_stack;
	struct node_list *List;
	struct list *organization;
	int i = 0, condition = 1;

	the_stack = (struct stack *)malloc(sizeof(struct stack *));
	the_stack->head = NULL;

	while (scanf("%s", operation) != EOF) {

		if (!strcmp(operation, "PUSH")) {

			List = (struct node_list *)malloc(sizeof(struct node_list *));
			organization = (struct list *)malloc(sizeof(struct list *));
			organization->first_node = List;

			condition = 1;
			i = 0;
			while (condition) {
				scanf("%c", &num01);
				if (num01 == '\n' && i == 1) {
					condition = 0;
				} else {
					scanf("%s", num02);
					int num = atoi(num02);
					add_num(organization, i, num);
				}
				i = 1;
			}

			push(the_stack, organization);
		} else if (!strcmp(operation, "POP")) {
			pop(the_stack);
		}
	}

	return 0;
}

//FUNCTION STACK
int push(struct stack *the_stack, struct list *organization)
{
	struct node_stack *new;

	new = (struct node_stack *)malloc(sizeof(struct node_stack *));

	if (new == NULL) {
		return 0;
	}

	new->next = the_stack->head;
	new->first_node = organization->first_node;
	the_stack->head = new;
	return 1;
}

void pop(struct stack *the_stack)
{
	struct node_stack *out;
	struct node_list *list;

	if (the_stack->head == NULL) {
		printf("\n");
		printf("EMPTY STACK");
	}

	else {
		out = the_stack->head;
		the_stack->head = out->next;

		list = out->first_node;
		printf("\n");
		while (list != NULL) {
			printf("%d", list->num);

			if (list->next != NULL) {
				printf(" ");
			}
			list = list->next;
		}

		free(out->first_node);
		free(out);
	}
}

//FUNCTION LIST
void add_num(struct list *organization, int i, int num)
{
	struct node_list *new, *lastProduct;
	lastProduct = organization->first_node;
	new = (struct node_list *)malloc(sizeof(struct node_list));
	if (i == 0) {
		lastProduct->num = num;
		lastProduct->next = NULL;
	} else {
		while (lastProduct->next != NULL) {
			lastProduct = lastProduct->next;
		}

		new->num = num;
		new->next = NULL;
		lastProduct->next = new;
	}
}