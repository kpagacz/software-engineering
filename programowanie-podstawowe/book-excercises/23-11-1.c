#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int tab[100];
    for(int i = 0; i < 100; i++) {
        tab[i] = rand() % 100;
    }

    int lower_bound, upper_bound;
    printf("Input two numbers between 0 and 99: ");
    scanf(" %i %i", &lower_bound, &upper_bound);
        int in_interval_counter = 0;

    printf("Original table:\n");
    for(int i = 0; i < 100; i++) {
        if(tab[i] >= lower_bound && tab[i] <= upper_bound) {
            in_interval_counter++;
        }
        printf("%i ", tab[i]);
    }
    printf("\n");
    
    int* in_interval_array = (int*) malloc(in_interval_counter * sizeof(int));

    int in_interval_array_index = 0;
    printf("New table:\n");
    for(int i = 0; i < 100; i++) {
        if(tab[i] >= lower_bound && tab[i] <= upper_bound) {
            in_interval_array[in_interval_array_index] = tab[i];
            printf("%i ", in_interval_array[in_interval_array_index]);
            in_interval_array_index++;
        }
    }

    return 0;
}