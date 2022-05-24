#include <stdio.h>
#include <stdlib.h>
#include "operaArray.h"
#include "myLib.h"

int main(void)
{
	int array_size, i;
        printf("Qual o tamanho do array? ");
	scanf("%d", &array_size);

	int array[array_size];

	for (i = 0; i < array_size; i++) {
		printf("Elemento %d : ", i);
		scanf("%d", &array[i]);
	}
	
	char option = 'b';
	int count = 1;
	while (option != 'S' && option != 's') {
		printf("\n\n-----MENU-----\n");
		printf("R - Inverter a Lista\n");
		printf("E - Contar numero de vezes que X aparece no Array\n");
		printf("U - Retorna os elementos que nao se repetem\n");
		printf("D - Deleta o enesimo elemento\n");
		printf("S - Para sair\n");
		printf("Opcao: ");
		scanf(" %c", &option);


		if (option != 'S' && option != 's') {
			int final_size = array_size;
			if (option ==  'R' || option == 'r'){
				newReverse(array, array_size);

			} else if (option == 'E' || option == 'e') {

				int num;
				printf("Qual numero deseja pesquisar? ");
				scanf("%d", &num);
				elemNum(array, array_size, num);

			} else if (option == 'U' || option == 'u') {

				unique(array, array_size);

			} else if (option == 'D' || option == 'd') {
				int n;

				printf("Posicao do numero que deseja deletar(Posicoes: 0 - %d)? ", array_size - count++);
				scanf("%d", &n);
				deleteN(array, array_size, n);
			}
		}
	}

	
        return 0;
}