#include<stdio.h>

int weirdZerosCounting(float tab[2][3], int tab_columns[3]) {
    int tab_columns_length = 0;
    int zeros_no = 0;
    float elements_in_column = 2;

    for(int i = 0; i < 3; i++) {
        zeros_no = 0;
        for(int j = 0; j < 2; j++) {
            if(tab[j][i] == 0) {
                zeros_no++;
            }
        }
        if(zeros_no >= elements_in_column * 0.5 && zeros_no < elements_in_column) {
            for(int j = 0; j < 2; j++) {
                tab[j][i] = 0;
            }
            tab_columns[tab_columns_length] = i;
            tab_columns_length++;
        }
    }


    return tab_columns_length;
}

int main(void) {
    float tab[2][3];

    printf("Input matrix (2v by 3c) elements:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%f", &tab[i][j]);
        }
    }

    int tab_columns[3];

    int tab_columns_length = weirdZerosCounting(tab, tab_columns);

    if(tab_columns_length > 0) {
        printf("Zeroed columns indices: ");
        for(int i = 0; i < tab_columns_length; i++) {
            printf("%i ", tab_columns[i]);
        }
        printf("\n");
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
            printf("%f ", tab[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No columns zeroed.\n");
    }
    return 0;
}