#include <stdio.h>
int count;

void transform_matrix(int *list);

int main(void)
{
	int num = -1;
	int list[9];
	count = 0;
	while (scanf("%d", &num) != EOF) {
		if (count < 9) {
			list[count] = num;
			count++;
		}
		if (count == 9) {
			transform_matrix(list);
		}
	}

	return 0;
}

void transform_matrix(int *list)
{
	int matrix[3][3], i, j, array_index = 0;

	for (i = 0; i < 3; i++) {

		for (j = 0; j < 3; j++) {
			matrix[i][j] = list[array_index];
			array_index++;
		}
	}

	if (matrix[1][0] == 0 && matrix[2][0] == 0 && matrix[2][1] == 0) {
		printf("Por baixo\n");
	} else if (matrix[0][1] == 0 && matrix[0][2] == 0 && matrix[1][2] == 0) {
		printf("Por cima\n");
	} else {
		printf("Nao pode atravessar\n");
	}

	count = 0;
}