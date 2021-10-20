#include <stdio.h>

void largest_square(int matrix_size, int matrix[matrix_size][matrix_size]);
int min(int num_one, int num_two, int num_tree);

int main(void)
{
	int matrix_size, i, j;

	scanf("%d", &matrix_size);

	int matrix[matrix_size][matrix_size];

	for (i = 0; i < matrix_size; i++) {
		for (j = 0; j < matrix_size; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	largest_square(matrix_size, matrix);

	return 1;
}

void largest_square(int matrix_size, int matrix[matrix_size][matrix_size])
{
	int result = 0, i, j, clone_matrix[matrix_size][matrix_size];

	for (i = 0; i < matrix_size; i++) {
		for (j = 0; j < matrix_size; j++) {
			clone_matrix[i][j] = matrix[i][j];
		}
	}

	for (i = 0; i < matrix_size; i++) {
		for (j = 0; j < matrix_size; j++) {
			if (matrix[i][j] == 1 && i != 0 && j != 0) {
				clone_matrix[i][j] = 1 + min(clone_matrix[i][j - 1], clone_matrix[i - 1][j], clone_matrix[i - 1][j - 1]);
			}

			if (clone_matrix[i][j] > result) {
				result = clone_matrix[i][j];
			}
		}
	}

	printf("%d", result * result);
}

int min(int num_one, int num_two, int num_tree)
{
	int numbers[3] = {num_one, num_two, num_tree};
	int result = numbers[0], i;

	for (i = 0; i < 3; i++) {
		if (numbers[i] < result) {
			result = numbers[i];
		}
	}
	return result;
}