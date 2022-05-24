#include <stdio.h>

void writeHeader(FILE *archive, char option)
{
	if (option ==  'R' || option == 'r'){
		fprintf(archive, "%s", "---Lista Invertida---");

	} else if (option == 'E' || option == 'e') {
		fprintf(archive, "%s", "---Quantidade de vezes que X aparece---");
	} else if (option == 'U' || option == 'u') {
		fprintf(archive, "%s", "---Números que não repetem---");
	} else if (option == 'D' || option == 'd') {
		fprintf(archive, "%s", "---Lista sem o enésimo termo---");
	}
}

void writeArchive(FILE *archive, char option, int size, int *array)
{	
	writeHeader(archive, option);
	fprintf(archive,"%s","\nResultado: ");

	
	for (int i = 0; i < size; i++) {
		if (array[i] != '\0') {
			fprintf(archive, "%d ", array[i]);
	
		}
	}
	
	fprintf(archive,"%s","\n\n");
}

void printResult(int size, int *result)
{	
	int i;
	printf("Resultado: ");
	for (i = 0; i < size; i++) {
		if (result[i] != '\0') {
			printf("%d ", result[i]);

		}

		
	}
}

void choicArchive(char option, int size, int *result)
{
	char option_archive;
	printf("\nQuer salvar os resultados em um arquivo chamado resultados.txt? ");
	scanf(" %c", &option_archive);

	if (option_archive == 'S' || option_archive == 's') {

		FILE *archive;
		archive = fopen("resultados.txt", "a");

		writeArchive(archive, option, size, result);

		fclose(archive);

		printf("Arquivo Salvo!");
	}
}