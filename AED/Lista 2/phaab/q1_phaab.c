#include <stdio.h>

int main(void){
    int lines, columns, i, j, num, amountSmaller, amountBigger, principalDiagon, secondDiagon;
    amountBigger =0;
    amountSmaller =0;
    principalDiagon =0;
    secondDiagon =0;

    scanf("%d %d",&lines,&columns);

    int matrix[lines][columns];

    for(i = 0; i < lines; i++){
        for(j = 0; j < columns; j++){

            scanf("%d", &num);
            matrix[i][j] = num;

            if(num > 0){
                amountBigger++;
            }
            else if(num < 0){
                amountSmaller++;
            }

        }
    }

    printf("Matriz formada:\n");
    for(i = 0; i < lines; i++){
        for(j = 0; j < columns; j++){

            printf("%d",matrix[i][j]);

            if(j < columns-1){
                printf(" ");
            }

        }

        if(i < lines){
            printf("\n");
        }
        
    }

    if(lines == columns){

        for (i = 0; i < lines; i++){
            for (j = 0; j < columns; j++){

                if(i == j){
                    principalDiagon+=matrix[i][j];
                }
            }

            secondDiagon += matrix[i][lines - 1 - i];
        }
        
        printf("A diagonal principal e secundaria tem valor(es) %d e %d respectivamente.\n", principalDiagon, secondDiagon);
    }

    else{
        printf("A diagonal principal e secundaria nao pode ser obtida.\n");
    }

    printf("A matriz possui %d numero(s) menor(es) que zero.\n", amountSmaller);
    printf("A matriz possui %d numero(s) maior(es) que zero.", amountBigger);

}