#include<stdlib.h>
#include<stdio.h>
#include "dynamic-arrays-toolbox.h"

float** selectItems(float** items, int items_no, int selected_items_count, int threshold) {
    float** selected_items = create2Darray(selected_items_count, 2);
    int selected_items_index = 0;
    for(int i = 0; i < items_no; i++) {
        if(items[i][1] > threshold) {
            for(int j = 0; j < 2; j++) {
                selected_items[selected_items_index][j] = items[i][j];
            }
            selected_items_index++;
        }
    }
    return selected_items;
}

int main(void) {
    int items_no;
    printf("Input number of items: ");
    scanf("%i", &items_no);

    float** items = create2Darray(items_no, 2);

    printf("Input items' prices and quantity:\n");
    read2Darray(items, items_no, 2);

    printf("Filter out items with quantity less or equal than: ");
    float threshold;
    scanf("%f", &threshold);

    /* counting selected items */
    int selected_items_count = 0;
    for(int i = 0; i < items_no; i++) {
        if(items[i][1] > threshold) {
            selected_items_count++;
        }
    }

    float** selected_items = selectItems(items, items_no, selected_items_count, threshold);
    printf("Selected items:\n");
    output2Darray(selected_items, selected_items_count, 2);
    return 0;
}