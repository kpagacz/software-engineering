#include<stdio.h>
#include<stdlib.h>


int main(void) {
    printf("Input number of measurements: ");
    int no;
    scanf("%i", &no);
    float* tab = malloc(no * sizeof(float));

    float mean;
    float sum = 0;

    printf("Input numbers: \n");
    for(int i = 0; i < no; i++) {
        scanf("%f", &tab[i]);
        sum = sum + tab[i];
    }

    mean = sum / no;

    printf("Mean is: %f", mean);
    free(tab);
    
    return 0;
}