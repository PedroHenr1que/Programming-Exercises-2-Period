#include <stdio.h>

int main(void){
    int columns = 0, lines = 0, i, j;

    scanf("%d\n", &columns);
    scanf("%d", &lines);

    int matrix[lines][columns];

    for(i = 0; i < lines; i++){
        for(j = 0; j < columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }


    for(i = 0; i < columns; i++){

        int votes = 0;
        for(j = 0; j < lines; j++){
            votes += matrix[j][i];
        }
        printf("Princesa %d: %d voto(s)\n", i + 1,votes);
    }
}