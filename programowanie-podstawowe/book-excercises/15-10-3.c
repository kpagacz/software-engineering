#include<stdio.h>

int menu() {
    int choice = -1;
    while(choice < 1 || choice > 3) {
        printf("Choose function number (1 2 3): ");
        scanf("%i", &choice);
    }

    return choice;
}

void changeMinWithMax(float tab[], int length) {
    int min_index = 0, max_index = 0;
    float tmp;

    /* finding min and max */
    for(int i = 0; i < length; i++) {
        if(tab[i] < tab[min_index]) min_index = i;
        if(tab[i] > tab[max_index]) max_index = i;
    }

    /* changing placaes */
    tmp = tab[max_index];
    tab[max_index] = tab[min_index];
    tab[min_index] = tmp;
}

void reverseElements(float tab[], int length) {
    float tmp;
    for(int i = 0; i < length / 2; i++) {
        tmp = tab[i];
        tab[i] = tab[length - 1 -i];
        tab[length - 1 - i] = tmp;
    }
}

void squaresAndCubes(float tab[], float tab_y[], float tab_z[], int length) {
    for(int i = 0; i < length; i++) {
        tab_y[i] = tab[i] * tab[i];
        tab_z[i] = tab_y[i] * tab[i];
    }
}

void printTab(float tab[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%f ", tab[i]);
    }
    printf("\n");
}

int main(void) {
    float tab[100], tab_y[100], tab_z[100];

    for(int i = 0; i < 100; i++) {
        tab[i] = 0.5 * (i + i + 1);
    }

    int choice = menu();
    int output_tab = 0;
    int output_tab_y = 0;
    int output_tab_z = 0;

    switch (choice)
    {
    case 1:
        printf("Change min with max:\n");
        changeMinWithMax(tab, 100);
        output_tab = 1;
        break;
    case 2:
        printf("Reverse order:\n");
        reverseElements(tab, 100);
        output_tab = 1;
        break;
    case 3:
        printf("Make tab_y of squares and tab_z of cubes:\n");
        squaresAndCubes(tab, tab_y, tab_z, 100);
        output_tab_y = 1;
        output_tab_z = 1;
    default:
        break;
    }

    if(output_tab) {
        printf("Tab:\n");
        printTab(tab, 100);
    }

    if(output_tab_y) {
        printf("tab_y:\n");
        printTab(tab_y, 100);
    }

    if(output_tab_z) {
        printf("tab_z:\n");
        printTab(tab_z, 100);
    }
    return 0;
}