#include <stdio.h>

int mut(int coins, int necessery_coins);

int main(void)
{
	int rope_amount = 0, coins = 0, necessery_coins = 0;

	while (scanf("%d%d%d", &rope_amount, &coins, &necessery_coins) != EOF) {
		int price;
		price = mut(rope_amount, necessery_coins);

		if (coins >= price) {
			printf("Sim\n");
		} else {
			printf("Nao\n");
		}
	}
	return 0;
}

int mut(int rope_amount, int necessery_coins)
{
	if (necessery_coins != 0) {
		return rope_amount + mut(rope_amount, necessery_coins - 1);
	} else {
		return 0;
	}
}