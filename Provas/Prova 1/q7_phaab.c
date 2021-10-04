#include <stdio.h>
#include <stdlib.h>

struct stack{
	struct stack_node *head;
};

struct stack_node{
	char character;
	struct stack_node *next;
};

int push(struct stack *the_stack, char character);
int pop(struct stack *the_stack);
int compare_one(struct stack *stack);
int is_empty(struct stack *stack);
void compare(struct stack *stack_open, struct stack *stack_close);
int pop_all(struct stack *the_stack);

int main(void)
{
	int times = 0, i, count, j, h, condition_one, x, count_new;
	struct stack *stack_open, *stack_close, *aux;

	stack_open = (struct stack *)malloc(sizeof(struct stack *));
	stack_close = (struct stack *)malloc(sizeof(struct stack *));
	aux = (struct stack *)malloc(sizeof(struct stack *));

	scanf("%d", &times);

	for (i = 0; i < times; i++) {
		char *line;
		line = (char *)malloc(100000 * sizeof(char));

		int condition = 1;
		scanf("%s", line);

		count = 0;
		while (line[count] != '\000') {
			count++;
		}

		char *line_correct;
		line_correct = (char *)malloc(count * sizeof(char));
		for (x = 0; x < count; x++) {
			line_correct[x] = line[x];
			push(aux, line_correct[x]);
		}

		if (count % 2 != 0) {
			printf("N\n");
		} else if (compare_one(aux)) {

			for (j = 0; (j < count || j < count_new) && condition; j++) {

				if (line[j] == '(') {

					if (line[j + 1] == ')') {
						line_correct[j] = '\000';
						line_correct[j + 1] = '\000';
						push(stack_open, line[j]);
						push(stack_close, line[j + 1]);
						j = -1;
					}
				} else if (line[j] == '[') {

					if (line[j + 1] == ']') {
						line_correct[j] = '\000';
						line_correct[j + 1] = '\000';
						push(stack_open, line[j]);
						push(stack_close, line[j + 1]);
						j = -1;
					}
				}

				else if (line[j] == '{') {

					if (line[j + 1] == '}') {
						line_correct[j] = '\000';
						line_correct[j + 1] = '\000';
						push(stack_open, line[j]);
						push(stack_close, line[j + 1]);
						j = -1;
					}
				}

				count_new = 0;
				for (h = 0; h < count; h++) {
					if (line_correct[h] != '\000') {
						count_new++;
					}
				}

				line = (char *)malloc(count_new * sizeof(char));
				int counter = 0;

				for (h = 0; h < count; h++) {
					if (line_correct[h] != '\000') {
						line[counter] = line_correct[h];
						counter++;
					}
				}

				line_correct = (char *)malloc(count_new * sizeof(char));

				for (h = 0; h < count_new; h++) {
					line_correct[h] = line[h];
				}
				count = count_new;
				if (count_new == 0) {
					condition = 0;
				}
			}

			if (condition == 0) {
				compare(stack_open, stack_close);
			} else {
				printf("N\n");
			}
		} else {
			printf("N\n");
		}

		pop_all(aux);
		pop_all(stack_open);
		pop_all(stack_close);
	}

	return 1;
}

int pop_all(struct stack *the_stack)
{
	struct stack_node *out;
	if (the_stack->head == NULL) {
		return 0;
	}

	while (the_stack->head != NULL) {
		out = the_stack->head;
		the_stack->head = out->next;

		free(out);
	}

	return 1;
}

int compare_one(struct stack *stack)
{
	struct stack_node *node = stack->head;
	int correct_bracketsO = 0, correct_slaO = 0, correct_issoO = 0, correct_bracketsC = 0, correct_slaC = 0, correct_issoC = 0;

	while (node != NULL) {

		if (node->character == '(') {
			correct_bracketsO++;
		} else if (node->character == '[') {
			correct_slaO++;
		} else if (node->character == '{') {
			correct_issoO++;
		} else if (node->character == ')') {
			correct_bracketsC++;
		} else if (node->character == ']') {
			correct_slaC++;
		} else {
			correct_issoC++;
		}

		node = node->next;
	}

	if (correct_bracketsO != correct_bracketsC || correct_slaO != correct_slaC || correct_issoO != correct_issoC) {
		return 0;
	} else {
		return 1;
	}
}

void compare(struct stack *stack_open, struct stack *stack_close)
{

	struct stack_node *node_open = stack_open->head;
	struct stack_node *node_close = stack_close->head;

	while (node_open != NULL && node_close != NULL) {

		if (node_open->character == '(' && node_close->character == ')') {
			node_open = node_open->next;
			node_close = node_close->next;
			pop(stack_close);
			pop(stack_open);
		} else if (node_open->character == '{' && node_close->character == '}') {
			node_open = node_open->next;
			node_close = node_close->next;
			pop(stack_close);
			pop(stack_open);
		} else if (node_open->character == '[' && node_close->character == ']') {
			node_open = node_open->next;
			node_close = node_close->next;
			pop(stack_close);
			pop(stack_open);
		}
	}

	if (is_empty(stack_open) && is_empty(stack_close)) {
		printf("S\n");
	} else {
		printf("N\n");
	}
}

int is_empty(struct stack *stack)
{
	if (stack->head == NULL) {
		return 1;
	}

	return 0;
}

int push(struct stack *the_stack, char character)
{

	struct stack_node *new;

	new = (struct stack_node *)malloc(sizeof(struct stack_node *));

	if (new == NULL) {
		return 0;
	}

	new->next = the_stack->head;
	new->character = character;
	the_stack->head = new;
	return 1;
}

int pop(struct stack *the_stack)
{
	struct stack_node *out;
	if (the_stack->head == NULL) {
		return 0;
	}

	out = the_stack->head;
	the_stack->head = out->next;

	free(out);

	return 1;
}