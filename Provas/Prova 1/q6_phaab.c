#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word{
	char word[10];
};

int binarySearch(int end, char *word_to_compare, struct word *ordered_words[end]);

int main(void)
{
	int amount_words, amount_words_to_compare, count, i;
	char word[10];

	scanf("%d%d", &amount_words, &amount_words_to_compare);

	struct word *ordered_words[amount_words];
	for (i = 0; i < amount_words; i++) {
		ordered_words[i] = malloc(sizeof(struct word));
	}

	for (count = 0; count < amount_words; count++) {

		scanf("%s", word);

		strncpy(ordered_words[count]->word, word, 10);
	}

	char word_to_compare[10];
	for (i = 0; i < amount_words_to_compare; i++) {
		scanf("%s", word_to_compare);

		binarySearch(amount_words - 1, word_to_compare, ordered_words);
	}

	for (count = 0; count < amount_words; count++) {
		free(ordered_words[count]);
	}
}

int binarySearch(int end, char *word_to_compare, struct word *ordered_words[end])
{

	int start = 0, middle, amount_letter_word_compare = 0, j;
	int letters_compared = 0;
	middle = (start + end) / 2;

	while (word_to_compare[amount_letter_word_compare] != '\000' && amount_letter_word_compare < 10) {
		amount_letter_word_compare++;
	}

	while (start <= end) {
		char word[10];
		int correct_letters = 0;
		strncpy(word, ordered_words[middle]->word, 10);

		int amount_letter_word = 0, times = 1;

		while (word[amount_letter_word] != '\000' && amount_letter_word < 10) {
			amount_letter_word++;
		}

		int result = 0;

		if (amount_letter_word < amount_letter_word_compare) {
			result = amount_letter_word_compare;
		} else if (amount_letter_word > amount_letter_word_compare) {
			result = amount_letter_word;
		} else {
			result = amount_letter_word;
		}

		for (j = 0; j < result; j++) {

			if (word_to_compare[j] != '\000' && word[j] != '\000') {
				if (word_to_compare[j] == word[j]) {
					correct_letters++;
					letters_compared++;

				} else if (word_to_compare[j] < word[j]) {
					end = middle - 1;
					letters_compared++;
					break;
				} else if (word_to_compare[j] > word[j]) {
					start = middle + 1;
					letters_compared++;
					break;
				} else {
					start = middle + 1;
				}
			} else if (amount_letter_word_compare > amount_letter_word) {
				start = middle + 1;
				break;
			} else {
				end = middle - 1;
				break;
			}
		}

		if (correct_letters == amount_letter_word_compare && amount_letter_word == amount_letter_word_compare) {
			printf("SIM %d\n", letters_compared);
			return 0;
		}

		middle = (start + end) / 2;
	}
	printf("NAO %d\n", letters_compared);
	return 0;
}