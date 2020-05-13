#include<stdio.h>
#include<stdlib.h>

/* creating */
float* create1Darray(int length) {
    float* arr = (float*) malloc(sizeof(float) * length);
    return arr;
}

float** create2Darray(int verses, int columns) {
    float** array = (float**) malloc(verses * sizeof(float*));

    for(int i = 0; i < verses; i++) {
        array[i] = (float*) malloc(columns * sizeof(float));
    }

    return array;
}

/* output */
void output1Darray(float* arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void output2Darray(float** array, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%.2f ", array[i][j]);
        }
        printf("\n");
    }
}

/* reading */
void read1Darray(float* array, int length) {
    printf("Input array elements: ");
    for(int i = 0; i < length; i++) {
        scanf("%f", array + i);
    }
}

void read2Darray(float** array, int verses, int columns) {
    for(int i = 0; i < verses; i++) {
        for(int j = 0; j < columns; j++) {
            scanf("%f", &array[i][j]);
        }
    }
}