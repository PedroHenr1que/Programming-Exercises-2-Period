#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int start = 0;
int size_of_str;
struct Node {
	int num;
	struct Node *node_left;
	struct Node *node_right;
};

struct Node * createTree(char *str);
struct Node * check(char *str);
int depth(struct Node *root,int x);
struct Node * buscarNo(struct Node *tree, int valor, struct Node *result);

int main(void)
{
	int i = 0;
	char str[100];

  
	scanf("%[^\n]", str);

	while (str[i] != '\000') {
		if (str[i] != ' ') {
			size_of_str++;
		}
		i++;
	}

	char str_correct[size_of_str - 2];
	int count = 0;
	for (i = 0; i < size_of_str; i++) {
		if (str[i+1] != ' ') {
			str_correct[count] = str[i+1];
			count++;
		}
	}
	struct Node *root, *result;
	root = check(str_correct);

	int num_search;
	scanf("%d", &num_search);

	if (buscarNo(root, num_search, result) != NULL) {
		printf("ESTA NA ARVORE\n%d", depth(root, num_search));

	} else{

		printf("NAO ESTA NA ARVORE");
	}
}

struct Node * check(char *str)
{
	if (str == NULL || size_of_str == 0) {
		return NULL;
	}

	return createTree(str);
}

struct Node * createTree(char *str)
{	
	if (isdigit(str[start])) {
		if (start >= size_of_str) {
			return NULL;
		}

		int neg = 0;

		if (str[start] == '-') {
			neg = 1;
			start++;
		}

		int num;
		int count = 0;
		while (start < size_of_str && isdigit(str[start])) {
			if (count == 0) {
				num = atoi(&str[start]);
			}
			count++;
			start++;
		}

		if (neg) {
			num = -num;
		}

		struct Node *root;
		root = malloc(sizeof(struct Node *));
		root->num = num;

		if (start >= size_of_str) {
			return root;
		}

		if (start < size_of_str && str[start] == '(') {
			start++;
			root->node_left = createTree(str);
		}

		if (start < size_of_str && str[start] == ')') {
			start++;
			return root;
		}

		if (start < size_of_str && str[start] == '(') {
			start++;
			root->node_right = createTree(str);
		}

		if (start < size_of_str && str[start] == ')') {
			start++;
			return root;
		}

		return root;
	} else {
		start++;
		return NULL;
	}
}

int depth(struct Node *root,int x)
{
	int level;
	level = -1;

	if(root) {
		if(root->num != x) {
			if (root->node_left && depth(root->node_left,x) > -1) {
				level = 1 + depth(root->node_left,x);
			}
			if (level <= 0) {
				if(root->node_right && depth(root->node_right,x) > -1) {
					level = 1 + depth(root->node_right,x);
				}
			}
		}
		else {
			level = 0;
		}
	}
	return level;
}

struct Node * buscarNo(struct Node *tree, int value, struct Node *result)
{ 
	
	if (tree != NULL) {
		if (value == tree->num) {
			result = tree;
		} else {
			result = buscarNo(tree->node_left, value, result);

			if (result == NULL) {
				result = buscarNo(tree->node_right, value, result);
			} else if (result->num != value) {
				result = buscarNo(tree->node_right, value, result);
			}
		}
	}

	return result;
}