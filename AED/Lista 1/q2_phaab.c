#include <stdio.h>

int main(){

    float value;
    int amount;

    amount =0;
    value =0;
    
    scanf("%f",&value);
    value = value * 100;

    if(value/10000 >= 1){
        amount = value/10000;
        value = value - amount * 10000;
        printf("%d nota(s) de R$ 100.00\n", amount);
    }

    if(value/5000 >= 1){
        amount = value/5000;
        value = value - amount * 5000;
        printf("%d nota(s) de R$ 50.00\n", amount);
    }

    if(value/2000 >= 1){
        amount = value/2000;
        value = value - amount * 2000;
        printf("%d nota(s) de R$ 20.00\n", amount);
    }

    if(value/1000 >= 1){
        amount = value/1000;
        value = value - amount * 1000;
        printf("%d nota(s) de R$ 10.00\n", amount);
    }

    if(value/500 >= 1){
        amount = value/500;
        value = value - amount * 500;
        printf("%d nota(s) de R$ 5.00\n", amount);
    }

    if(value/200 >= 1){
        amount = value/200;
        value = value - amount * 200;
        printf("%d nota(s) de R$ 2.00\n", amount);
    }

    if(value/100 >= 1){
        amount = value/100;
        value = value - amount * 100;
        printf("%d moeda(s) de R$ 1.00\n", amount);
    }

    if(value/50 >= 1){
        amount = value/50;
        value = value - amount * 50;
        printf("%d moeda(s) de R$ 0.50\n", amount);
    }

    if(value/25 >= 1){
        amount = value/25;
        value = value - amount * 25;
        printf("%d moeda(s) de R$ 0.25\n", amount);
    }

    if(value/10 >= 1){
        amount = value/10;
        value = value - amount * 10;
        printf("%d moeda(s) de R$ 0.10\n", amount);
    }

    if(value/5 >= 1){
        amount = value/5;
        value = value - amount * 5;
        printf("%d moeda(s) de R$ 0.05\n", amount);
    }

    if(value/1 >= 1){
        amount = value/1;
        value = value - amount * 1;
        printf("%d moeda(s) de R$ 0.01", amount);
    }

    return 0;
}