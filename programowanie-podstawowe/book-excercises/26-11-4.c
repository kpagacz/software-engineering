#include<stdlib.h>
#include<stdio.h>
#include "dynamic-arrays-toolbox.h"

float* f_1(float** matrix, int positive_count, int rows, int columns) {
    float* positive_array = create1Darray(positive_count);
    int positive_array_index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j] > 0) {
                positive_array[positive_array_index] = matrix[i][j];
                positive_array_index++;
            }
        }
    }
    return positive_array;
}

float* f_2(float** matrix, int positive_count, int rows, int columns) {
    float* positive_array = create1Darray(positive_count);
    int positive_array_index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j] < 0) {
                positive_array[positive_array_index] = matrix[i][j];
                positive_array_index++;
            }
        }
    }
    return positive_array;
}

int main(void) {
    int rows, columns;
    printf("Input dimensions of 2D matrix: ");
    scanf("%i %i", &rows, &columns);

    float** matrix = create2Darray(rows, columns);

    printf("Input matrix elements:\n");
    read2Darray(matrix, rows, columns);

    /* counting positives for f_1 */
    int positive_count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j] > 0) {
                positive_count++;
            }
        }
    }

    float* positives = f_1(matrix, positive_count, rows, columns);
    printf("Positives array:\n");
    output1Darray(positives, positive_count);

    /* counting negatives for f_2 */
    int negative_count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j] < 0) {
                negative_count++;
            }
        }
    }

    float* negatives = f_2(matrix, negative_count, rows, columns);
    printf("Negatives array:\n");
    output1Darray(negatives, negative_count);

    return 0;
}