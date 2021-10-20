#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"

void newReverse(int *array, int size)
{
	int aux[size];
	int count = 0;
        int i;

	for (i = size - 1; i >= 0; i--) {
                aux[count] = array[i];
                count++;
	}

	for (i = 0; i < size; i++) {
		array[i] = aux[i];
	}

        printResult(size, array);
        choicArchive('r', size, array);
}

void elemNum(int *array, int size, int num)
{
	int times = 0;
        int result[1];
	for (int i = 0; i < size; i++) {
		if (array[i] == num && array[i] != '\0') {
			times++;
		}
	}

        result[0] = times;
        printResult(1, result);
        choicArchive('e', 1, result);
}

void unique(int *array, int size)
{       
        int result[size];
        int count = 0, i = 0;

        for (i = 0; i < size; i++) {

                if (array[i] != '\0') {
                        int num = array[i];
                        int times = 0;
                        for (int j = 0; j < size; j++) {
                                if (num == array[j] && array[j] != '\0') {
                                        times++;
                                }
                        }

                        if (times == 1) {
                                result[count] = num; 
                                count++;
                        }
                }
        }

        printResult(count, result);
        choicArchive('u', count, result);
}

void deleteN(int *array, int size, int n)
{       
        int count = 0, condition = 1;

        for (int i = 0; i < size && condition; i++) {
                if (count == n && array[i] != '\0') {
                        array[i] = '\0';
                        condition = 0;
                } else if (array[i] != '\0') {
                        count++;
                }
        }

        printResult(size, array);
        choicArchive('d', size, array);
}