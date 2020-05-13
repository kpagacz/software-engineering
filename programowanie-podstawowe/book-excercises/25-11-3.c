#include<stdlib.h>
#include<stdio.h>

float* create1Darray(int length) {
    float* arr = (float*) malloc(sizeof(float) * length);
    return arr;
}

void output1Darray(float* arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void read1Darray(float* array, int length) {
    printf("Input array elements: ");
    for(int i = 0; i < length; i++) {
        scanf("%f", array + i);
    }
}


int main(void) {
    int tab[100];
    int non_zero_counter = 0;

    for(int i = 0; i < 100; i++) {
        tab[i] = rand() % 10;
        if(tab[i] != 0) {
            non_zero_counter++;
        }
    }

    if(non_zero_counter != 0) {
        float* new_array = create1Darray(non_zero_counter);
        int new_array_index = 0;
        for(int i = 0; i < 100; i++) {
            if(tab[i] != 0) {
                new_array[new_array_index] = tab[i];
                new_array_index++;
            }
        }
        printf("Non-zero array:\n");
        output1Darray(new_array, non_zero_counter);
    }
    
    return 0;
}