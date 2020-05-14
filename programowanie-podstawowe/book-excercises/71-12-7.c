#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char** words, int index_a, int index_b) {
    char* tmp = malloc(strlen(words[index_a]) * sizeof(char));
    strcpy(tmp, words[index_a]);

    strcpy(words[index_a], words[index_b]);
    strcpy(words[index_b], tmp);
}

int main(void) {
    int number_of_words = 5, length_of_words = 3;
    char** words = malloc(number_of_words * sizeof(char*));
    for(int i = 0; i < number_of_words; i++) {
        words[i] = malloc(sizeof(char) * (length_of_words + 1));
    }

    /* input */
    printf("Input %i words: ", number_of_words);
    for(int i = 0; i < number_of_words; i++) {
        scanf("%s", words[i]);
    }

    /* bubble sort */
    for(int i = 0; i < number_of_words; i++) {
        for(int j = 1; j < number_of_words - i; j++) {
            if(strcmp(words[j - 1], words[j]) > 0) swap(words, j - 1, j);
        }
    }

    /* output */
    for(int i = 0; i < number_of_words; i++) {
        printf("%s\n", words[i]);
    }

    for(int i = 0; i < number_of_words; i++) {
        free(words[i]);
    }

    free(words);

    return 0;
}