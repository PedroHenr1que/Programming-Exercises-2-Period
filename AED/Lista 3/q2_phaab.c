#include <stdio.h>
int binarySearch(int *array, int value, int end);
int findLineAndColum(float result, int columns);

int main(void){
    int lines, arraySize,i, columns;

    scanf("%d %d", &lines, &columns);

    arraySize = lines * columns;
    int array[arraySize];

    for (i = 0; i < arraySize; i++){
        scanf("%d", &array[i]);
    }
    
    int searchSize;
    scanf("%d", &searchSize);

    int searchArray[searchSize];

    for (i = 0; i < searchSize; i++){
        scanf("%d", &searchArray[i]);
    }
    
    for(i = 0; i < searchSize; i++){
        float result;
        result = binarySearch(array, searchArray[i], arraySize);

        if (result == -1){
            printf("NO\n");
        }

        else{
            findLineAndColum(result, columns);
        }
        
    }
    
}

int findLineAndColum(float result, int columns){
    int line = 0, colum = 0;

    line = result/columns;

    colum = result-(columns*line);

    printf("YES WITH %d AND %d\n",line + 1,colum + 1);
}

int binarySearch(int *array, int value, int end){
    int start = 0;
    int middle = (start + end) / 2;

    while (start <= end){
        
        if(value == array[middle]){
            return middle;
        }

        else{
            if (value < array[middle]){
                end = middle - 1;
            }
            else{
                start = middle + 1;
            }
        }
        middle = (start + end) / 2;
    }

    return -1;
}