#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//LIST CARDS
struct list_card{
	int list_size;
	struct node_list_card *first_node_card;
};

struct node_list_card{
	char name[100];
	struct node_circle_list *numbers;
	char name_next[100];
	struct node_list_card *next;
};

//LIST NUM
struct circle_list{
	struct node_circle_list *first_node_circle;
};

struct node_circle_list{
	int num;
	struct node_circle_list *next;
};

void add_num(struct circle_list *the_circle_list, int i, int num);
int add_card(struct list_card *the_card_list, char *name, char *next_name, struct circle_list *the_circle_list, int position);
int compare_cards(struct list_card *the_card_list, char *name_compare, int num_position, int card_amount);
void pop_list_card(struct list_card *the_card_list);
void pop_circle_list(struct node_circle_list *node);

int main(void)
{
	int card_amount, j, number_amount, num, i;
	char name[100], name_next[100];
	struct list_card *the_card_list;
	struct node_list_card *first_node_list;

	the_card_list = (struct list_card *)malloc(sizeof(struct list_card *));

	scanf("%d", &card_amount);

	for (j = 0; j < card_amount; j++) {
		scanf(" %[^\n]", name);
		scanf("%d", &number_amount);

		struct circle_list *the_circle_list;
		struct node_circle_list *first_circle_node;

		the_circle_list = (struct circle_list *)malloc(sizeof(struct circle_list *));
		first_circle_node = (struct node_circle_list *)malloc(sizeof(struct node_circle_list *));
		the_circle_list->first_node_circle = first_circle_node;

		for (i = 0; i < number_amount; i++) {
			scanf("%d", &num);
			add_num(the_circle_list, i, num);
		}

		scanf(" %[^\n]", name_next);

		if (j == 0) {
			add_card(the_card_list, name, name_next, the_circle_list, 0);
		} else {
			struct node_list_card *aux;
			aux = the_card_list->first_node_card;
			int counter = 0;
			int condition = 1;
			while (aux != NULL && condition == 1) {
				if (strcmp(name, aux->name) < 0) {
					add_card(the_card_list, name, name_next, the_circle_list, counter);
					condition = 0;
				} else if (aux->next == NULL) {
					add_card(the_card_list, name, name_next, the_circle_list, counter + 1);
					condition = 0;
				}
				aux = aux->next;
				counter++;
			}
		}
		free(the_circle_list);
	}
	char name_to_compare[100];
	scanf(" %[^\n]", name_to_compare);
	compare_cards(the_card_list, name_to_compare, 0, card_amount);

	pop_list_card(the_card_list);
	return 0;
}

int compare_cards(struct list_card *the_card_list, char *name_compare, int num_position, int card_amount)
{
	int count = 0;
	struct node_list_card *node_list;
	node_list = the_card_list->first_node_card;

	while (strcmp(node_list->name, name_compare)) {
		node_list = node_list->next;
		count++;
	}

	printf("%d\n", count);

	int i, num;
	struct node_circle_list *node_c_list;
	node_c_list = node_list->numbers;

	for (i = 0; i < num_position; i++) {
		node_c_list = node_c_list->next;
	}

	printf("%d\n", node_c_list->num);

	if (num_position + 1 < card_amount) {
		compare_cards(the_card_list, node_list->name_next, num_position + 1, card_amount);
	}

	return 0;
}

int add_card(struct list_card *the_card_list, char *name, char *next_name, struct circle_list *the_circle_list, int position)
{
	struct node_list_card *new, *before;
	int i;

	if (position > the_card_list->list_size + 1) {
		return 0;
	} else {
		new = (struct node_list_card *)malloc(sizeof(struct node_list_card));
		if (position == 0) {
			the_card_list->list_size = the_card_list->list_size + 1;

			new->numbers = the_circle_list->first_node_circle;
			strncpy(new->name, name, 100);
			strncpy(new->name_next, next_name, 100);
			new->next = the_card_list->first_node_card;

			the_card_list->first_node_card = new;
			return 1;
		} else {
			if (new == NULL) {
				return 0;
			} else {
				before = the_card_list->first_node_card;

				for (i = 0; position - 1 > i; i++) {
					before = before->next;
				}

				new->next = before->next;

				new->numbers = the_circle_list->first_node_circle;
				strncpy(new->name, name, 100);
				strncpy(new->name_next, next_name, 100);
				before->next = new;

				the_card_list->list_size = the_card_list->list_size + 1;
				return 1;
			}
		}

	}
}

void add_num(struct circle_list *the_circle_list, int i, int num)
{
	struct node_circle_list *new, *lastProduct;
	lastProduct = the_circle_list->first_node_circle;
	new = (struct node_circle_list *)malloc(sizeof(struct node_circle_list));

	if (i == 0) {
		lastProduct->num = num;
		lastProduct->next = lastProduct;
	} else {
		while (lastProduct->next != the_circle_list->first_node_circle) {
			lastProduct = lastProduct->next;
		}

		new->num = num;
		new->next = the_circle_list->first_node_circle;
		lastProduct->next = new;
	}
}

void pop_list_card(struct list_card *the_card_list)
{
	struct node_list_card *node, *before;

	node = the_card_list->first_node_card;

	while (node != NULL) {
		before = node;
		pop_circle_list(node->numbers);
		node = node->next;
		free(before);
	}
	free(the_card_list);
}

void pop_circle_list(struct node_circle_list *node)
{
	int condition = 1;
	struct node_circle_list *before, *first_node;
	first_node = node;
	while (node != first_node || condition) {
		before = node;
		node = node->next;
		free(before);
		condition = 0;
	}
}