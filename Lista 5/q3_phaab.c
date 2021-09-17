#include <stdio.h>
#include <stdlib.h>

struct Product{
    char name;
    float value;
    int amount;
    struct Product *next;
};

typedef struct{
    int size;
    struct Product *data;
}List;

char getOperation(char *line);
int getProductValue(char *line);
char getProductName(char *line);
int getProductAmount(char *line);
List* creatList();

int main(void){
    char line[30];
    char *operation, *productName;
    float productValue;
    int productAmount;
    List *LIST;

    LIST = creatList();

    while(scanf("%[^\n]", line) != EOF){
        operation = getOperation(line);

        if(*operation == "INSERIR"){
            productName = getProductName(line);
            productValue = getProductValue(line);
            productAmount = getProductAmount(line);

            addProduct(LIST, productName, productValue, productAmount);
        }
    }
}

void addProduct(List *LIST, char *productName, float productValue, int productAmount){
    struct Product *new;
    List *lastProduct;

    
    lastProduct = LIST;
    
    while(lastProduct->data->next != NULL){
        lastProduct->data = lastProduct->data->next;
    }

    new = (struct Product *)malloc(sizeof(struct Product));
    new->name = *productName;
    new->value = productValue;
    new->amount = productAmount;

    lastProduct->data->next = new;
}

int getProductAmount(char *line){
    int i,amount = 0,condition = 0;
    char amountChar;

    for(i = 0; condition;i++){
        if(line[i]==NULL){
            amountChar = line[i - 1];
        }
    }

    amount = atoi(amountChar);

    return amount;
}

char getProductName(char *line){
    int i, condition = 1,spaces = 0,j = 0;
    char name[10];

    for(i = 0; condition; i++){

        if(line[i] == ' '){
            spaces++;
        }

        else if(spaces == 1){
            name[j] = line[i];
            j++;
        }

        else{
            condition = 0;
        }
    }

    return name;
}


int getProductValue(char *line){
    int i,condition = 1,spaces = 0,j = 0;
    float num = 0.0;
    char numStr[6];

    for(i = 0; condition; i++){

        if(line[i] == ' '){
            spaces ++;
        }

        else if(spaces>=2){

            if(spaces < 3){
                numStr[j] = line[i];
                j++;
            }
            else{
                condition = 0;
            }
        }
    
    }

    num = atof(numStr);

    return num;
}

char getOperation(char *line){
    int i;
    int condition = 1;
    //char fun[12];
    char * fun = (char *) calloc (12, sizeof (char));

    for(i = 0; condition; i++){

        if(line[i]!=' ' && line[i]!=NULL){
            fun[i] = line[i];    
        }
        else{
            condition = 0;
        }
    }

    return fun;
}

List* creatList(){
    List *theList;
    theList = (List *)malloc(sizeof(List));

    if(theList != NULL){
        theList->size = 0;
        theList->data = NULL;
    }

    return(theList);
}