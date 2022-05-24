#include <stdio.h>

int main(){

    int amount, total, cups;
    char letter;

    amount = 0;
    total = 0;
    cups = 0;

    for (int i = 0; i < 7; i++){

        scanf("%d\n", &amount);
        scanf("%c", &letter);
        
        
        if (letter == 'P' || letter == 'p'){
            total += 10 * amount;
        }

        else if (letter == 'G' || letter == 'g'){
            total += 16 * amount;
        }

    }

    cups = (total * 2) / 7;

    printf("%d\n", total);
    printf("%d", cups);

    return 0;
}