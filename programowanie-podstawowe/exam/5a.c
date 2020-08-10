#include<stdio.h>
#include<stdlib.h>

// zrobiłem to na wskaźnikach zanim zobaczyłem, że jest osobny dział wskaźniki
// jeśli robiłbym to na tablicach, to zamiast alokować pamięć, użyłbym tablicy
// o stałym rozmiarze, np:
// int tab[100]
int main(void) {
    printf("Input number of measurements: ");
    int no;
    scanf("%i", &no);
    float* tab = malloc(no * sizeof(float));

    int iscorrect = 0;

    while(!iscorrect) {
        printf("Input numbers: \n");
        for(int i = 0; i < no; i++) {
            scanf("%f", &tab[i]);
        }

        for(int i = 0; i < no; i++) {
            printf("%f ", tab[i]);
        }
        printf("\n");
    
        printf("Is this correct? (y or n)\n");
        char c;
        scanf(" %c", &c);
        if(c == 'y') {
            iscorrect = 1;
        }
    }
    free(tab);
    return 0;
}