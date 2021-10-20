#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) a>b?a:b

int conditionAVL = 0;

struct Node {
        int num;
        int hight;
        struct Node *left;
        struct Node *right;
};

int hight(struct Node *no);
void updateHight(struct Node *no);
struct Node * simpleRotationLeft(struct Node *root);
struct Node * simpleRotationRight(struct Node *root);
struct Node * doubleRotationLeft(struct Node *root);
struct Node * doubleRotationRight(struct Node *root);
void printAVL(struct Node *root, int condition);
struct Node * insertAVL(int x, struct Node *root, struct Node *startRoot);
void preOrderPrint(struct Node *node);

int main(void)
{
        struct Node *root;
        int num;

	while (scanf("%d", &num) != EOF) {
		printf("\nAdicionando %d", num);
		root = insertAVL(num, root, root);

		if (conditionAVL) {
			printAVL(root, 1); //print avl depois balanceamento
		} else {
			printAVL(root, 2); //print avl, não houve balanceamento
		}
	}
}

int hight(struct Node *no)
{
        if (no == NULL) {
                return 0;
        } else {
                return no->hight;
        }
}

void updateHight(struct Node *no)
{
        int hightR;
        int hightL;
        int hightNode;

        if (no != NULL) {
                hightR = hight(no->right);
                hightL = hight(no->left);
                hightNode = MAX(hightR, hightL);
                no->hight = hightNode+1;
        }
}

struct Node * simpleRotationLeft(struct Node *root)
{
        struct Node *aux;

        aux = malloc(sizeof(struct Node *));
        aux = root->right;
        root->right = aux->left;
        aux->left = root;
        updateHight(root->left);
        updateHight(root);
        return aux;
}

struct Node * simpleRotationRight(struct Node *root)
{
        struct Node *aux;

        aux = malloc(sizeof(struct Node *));
        aux = root->left;
        root->left = aux->right;
        aux->right = root;
        updateHight(root->right);
        updateHight(root);
        return aux;
}

struct Node * doubleRotationLeft(struct Node *root)
{
        struct Node *result;

        result = malloc(sizeof(struct Node *));
        root->right = simpleRotationRight(root->right);
        result = simpleRotationLeft(root);
        return result;
}

struct Node * doubleRotationRight(struct Node *root)
{
        struct Node *result;

        result = malloc(sizeof(struct Node *));
        root->left = simpleRotationLeft(root->left);
        result = simpleRotationRight(root);
        return result;
}

struct Node * insertAVL(int x, struct Node *root, struct Node *startRoot)
{
        if (root == NULL) {
                root = malloc(sizeof(struct Node));
                root->num = x;
                root->left = NULL;
                root->right = NULL;
                root->hight = 1;
        } else {

                if (x < root->num) {
                        root->left = insertAVL(x, root->left, startRoot);
			
                        if ((hight(root->left) - hight(root->right)) == 2) {
				printAVL(startRoot, 0); //print avl antes do balanceamento
                                if (x < root->left->num) {
                                        root = simpleRotationRight(root);
                                } else {
                                        root = doubleRotationRight(root);
                                }

				conditionAVL = 1;// para print avl depois do balancemanto
                        } else {
				conditionAVL = 0;// quando não foi necessario balanceamento
			}
                } else {
                        root->right = insertAVL(x, root->right, startRoot);

                        if ((hight(root->right) - hight(root->left)) == 2) {
				printAVL(startRoot, 0);
                                if (x > root->right->num) {
                                        root = simpleRotationLeft(root);
                                } else {
                                        root = doubleRotationLeft(root);
                                }

				conditionAVL = 1;// para print avl depois do balancemanto
                        } else {
				conditionAVL = 0;// quando não foi necessario balanceamento
			}
                }
                updateHight(root);
        }

        return root;
}

void printAVL(struct Node *root, int condition)
{

	if (condition == 0) {
		printf("Antes de ajustar balanceamento...\n\t");
		preOrderPrint(root);
		prinft("\n----");

	} else if (condition == 1) {
		printf("Depois de ajustar balanceamento...\n\t");
		preOrderPrint(root);
		prinft("\n----");

	} else {
		printf("Continuou AVL...\n\t");
		preOrderPrint(root);;
		prinft("\n----");

	}
}

void preOrderPrint(struct Node *node)
{
	if (node != NULL) {
		printf("( ");
		printf("%d", node->num);
		preOrderPrint(node->left);
		printf(" )");
		preOrderPrint(node->right);
		printf(" )");
	} else {
		printf("( ");
	}
}