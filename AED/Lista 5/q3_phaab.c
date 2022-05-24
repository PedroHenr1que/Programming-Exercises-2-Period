#include <stdio.h>
#include <stdlib.h>

typedef struct{
    struct Element *start;
    struct Element *end;
}Queue;

struct Element{
    int id;
    int age;
    struct Element *next;
};

void insert(Queue *theQueue, int idNew,int ageNew);
int removePatient(Queue *theQueue);
void printQueue(Queue *theQueueNoSeniors,Queue *theQueueSeniors);

int main(void){
    Queue *theQueueSeniors,*theQueueNoSeniors;
    char operation = ' ';
    int id = 0, age = 0, i = 0,priority;

    theQueueSeniors = (Queue *)malloc(sizeof(Queue *));
    theQueueNoSeniors = (Queue *)malloc(sizeof(Queue *));

    scanf("%d", &priority);
    while(operation != 'f'){
        scanf(" %c", &operation);
        if(operation == 'a'){
            scanf("%d%d", &id,&age);

            if(age > 60){
                insert(theQueueSeniors, id, age);
            }
            else{
                insert(theQueueNoSeniors, id, age);
            }
        }
        
        else if(operation == 'r'){

            if(theQueueSeniors->start != NULL && i < priority){
                removePatient(theQueueSeniors);
                i++;
            }
            
            else if(theQueueNoSeniors->start != NULL){
                removePatient(theQueueNoSeniors);
                i = 0;
            }

            else{
                removePatient(theQueueSeniors);
                i = 0;
            }
        }

        else if(operation == 'i'){
            printQueue(theQueueNoSeniors, theQueueSeniors);
        }

    }
}

void printQueue(Queue *theQueueNoSeniors,Queue *theQueueSeniors){

    struct Element *patientSeniors = theQueueSeniors->start, *patientNoSeniors = theQueueNoSeniors->start;

    printf("\n\nfila de idosos:");
    if(patientSeniors == NULL){
        printf("\nfila vazia!");
    }
    else{
        while(patientSeniors != NULL){
            printf("\nID: %d IDADE: %d", patientSeniors->id,patientSeniors->age);
            patientSeniors = patientSeniors->next;
        }
    }
    

    printf("\nfila de nao-idosos:");
    if(patientNoSeniors == NULL){
        printf("\nfila vazia!");
    }
    else{
        while(patientNoSeniors != NULL){
            printf("\nID: %d IDADE: %d", patientNoSeniors->id,patientNoSeniors->age);
            patientNoSeniors = patientNoSeniors->next;
        }
    }
    printf("\n----------");
}

void insert(Queue *theQueue, int idNew,int ageNew){

    struct Element *new;
    new = (struct Element *)malloc(sizeof(struct Element *));

    new->next = NULL;
    new->id = idNew;
    new->age = ageNew;

    if(theQueue->start == NULL){
        theQueue->end = new;
        theQueue->start = new;
    }
    else{
        theQueue->end->next = new;
        theQueue->end = new;
    }
}

int removePatient(Queue *theQueue){
    struct Element *out;

    if(theQueue->start == NULL){
      theQueue->end = NULL;
      return(0);
    }
    
    out = theQueue->start;
    theQueue->start = out->next;

    
    free(out);

    return(1);
}