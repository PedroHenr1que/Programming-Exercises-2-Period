#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
    char name[12];
    float value;
    int amount;
    struct Product *next;
};

struct Element{
  struct Product *firstNode;
};

void addProduct(char *productName, float productValue, int productAmount,struct Element *organization, int i);
void removeProduct(char *productName, int amountToBeRemoved,struct Element *organization);
void removeGroup(float price,struct Element *organization);
void consult(struct Element *organizatio);
void searchName(char *productName, struct Element *organization);
void removeTheProduct(struct Product *product,struct Element *organization);

int main(void){
    char operation[12];
    char productName[12];
    float productValue, price;
    int productAmount, i=0;
    struct Product *LIST;
    struct Element *organization;

    organization = (struct Element *)malloc(sizeof(struct Element));
    LIST = (struct Product *)malloc(sizeof(struct Product));
    organization->firstNode = LIST;

    while(scanf("%s", operation) != EOF){
          
        if(!strcmp(operation, "INSERIR")){
            scanf("%s%f%d", productName, &productValue, &productAmount);

            addProduct(productName, productValue, productAmount, organization, i);
            i++;
        }

        else if(!strcmp(operation, "REMOVER")){
           scanf("%s%d", productName, &productAmount); 
           removeProduct(productName,productAmount, organization);
        }

        else if(!strcmp(operation, "REMOVERGRUPO")){
          scanf("%f", &price);
          removeGroup(price, organization);
        }

        else if(!strcmp(operation, "CONSULTAR")){
          consult(organization);
        }

        else if(!strcmp(operation, "PROCURAR")){
          scanf("%s", productName);
          searchName(productName, organization);
        }
    }
}

void searchName(char *productName, struct Element *organization){
  struct Product *product;
  int condition = 0;

  product = organization->firstNode;

  while(!condition && product != NULL){
    if(!strcmp(product->name,productName)){
      printf("\n%s\n- %0.1f\n- %d\n", productName,product->value,product->amount);
      condition = 1;
    }
    product = product->next;
  }

  if(condition == 0){
    printf("\n%s nao foi encontrado.\n", productName);
  }
  
}

void consult(struct Element *organization){
  struct Product *product;
  float value = 0;
  int condition = 1;

  product = organization->firstNode;

  while(product != NULL){

    value += product->value*product->amount;
  
    product = product -> next;
  }

  printf("\nAtualmente a lista esta em R$%0.1f\n", value);
}

void removeGroup(float price, struct Element *organization){
  struct Product *product,*before;

  before = NULL;
  product = organization->firstNode;
  
  while(product != NULL){
    if(product->value*100 > price*100){
      if(before == NULL){
        organization->firstNode = product->next;
      }
      else{
        before->next = product->next;
      }
    }

    if(!(product->value*100 > price*100)){
      before = product;
    }

    product = product->next;

  }

}

void removeTheProduct(struct Product *productToBeRemoved,struct Element *organization){
  struct Product *product,*before;
  int condition = 1;

  before = NULL;
  product = organization->firstNode;
  
  while(product != NULL && condition){
    if(product == productToBeRemoved){
      if(before == NULL){
        organization->firstNode = product->next;
      }
      else{
        before->next = product->next;
      }
      condition = 0;
    }

    if(!(product == productToBeRemoved)){
      before = product;
    }

    product = product->next;
  }
  
}

void removeProduct(char *productName, int amountToBeRemoved,struct Element *organization){
  struct Product *product;
  product = organization->firstNode;


  while(strcmp(product->name,productName)){
  
    product = product->next;
  }

  if(product->amount == amountToBeRemoved){
    removeTheProduct(product,organization);
  }
  else{
    product->amount = product->amount - amountToBeRemoved;
  }
  
}

void addProduct(char *productName, float productValue, int productAmount, struct Element *organization,int i){
    struct Product *new, *lastProduct;
    
    lastProduct = organization->firstNode;
    new = (struct Product *)malloc(sizeof(struct Product));
    
    if(i == 0){
      lastProduct->amount = productAmount;
      lastProduct->value = productValue;
      strncpy(lastProduct->name,productName,12);
      lastProduct->next = NULL;
    }

    else{
    
      while(lastProduct->next != NULL){
        lastProduct = lastProduct->next;
      }

      strncpy(new->name,productName,12);
      new->value = productValue;
      new->amount = productAmount;
      new->next = NULL;
      lastProduct->next = new;
    }
    
}