#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    struct Element *head;
}stack;

struct Element{
    int info;
    struct Element *next;
};

int push(stack *theStack, int value);
int pop(stack *theStack);
void pBiggestSmallest(stack *theStack);

int main(void){
    stack *theStack;
    char operation[4];
    int value;

    theStack = (stack *)malloc(sizeof(stack));


    while(scanf("\n%s", operation) != EOF){

        if(!strcmp(operation, "push")){
            scanf("%d", &value);
            push(theStack, value);
        }
        else if(!strcmp(operation, "pop")){
            pop(theStack);
        }
        else{
          pBiggestSmallest(theStack);
        }
    }

}

void pBiggestSmallest(stack *theStack){
    int biggest = 0, smallest = 0, i = 0;

    struct Element *node = theStack->head;

    if(node->next != NULL){
        while(node != NULL){

            if(i == 0){
                biggest = node->info;
                smallest = node->info;
            }
            else{
                if(node->info > biggest){
                    biggest = node->info;
                }
                else if(node->info < smallest){
                    smallest = node->info;
                }

            }
            i++;
            node = node->next;
        }

        printf("\n%d",biggest - smallest);
    }

    else{
        printf("\n%d", 0);
    }
    
}

int push(stack *theStack, int value){

    struct Element *new;

    new = (struct Element *)malloc(sizeof(struct Element *));

    if(new == NULL){
        return(0);
    }


    new->next = theStack->head;
    new->info = value;
    theStack->head = new;
    return(1);
}

int pop(stack *theStack){
    struct Element *out;
    
    if(theStack->head == NULL){
        return(0);
    }

    out = theStack->head;
    theStack->head = out->next;

    printf("\n%d",out->info);

    free(out);
    return(1);
}