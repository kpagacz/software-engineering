#include<stdio.h>

int customSieve(float tab[2][3], float tab_d[6], float tab_u[6], int* tab_d_length, int* tab_u_length) {
    int number_of_zeros = 0;
    *tab_d_length = 0;
    *tab_u_length = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            if(tab[i][j] == 0) {
                number_of_zeros++;
            }
            if(tab[i][j] > 0) {
                tab_d[*tab_d_length] = tab[i][j];
                (*tab_d_length)++;
            }
            if(tab[i][j] < 0) {
                tab_u[*tab_u_length] = tab[i][j];
                (*tab_u_length)++;
            }
        }
    }
    
    return number_of_zeros;
}


int main(void) {
    float tab[2][3];

    printf("Input matrix (2v by 3c) elements:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%f", &tab[i][j]);
        }
    }

    float tab_d[6], tab_u[6];
    int tab_d_length = 0, tab_u_length = 0;
    int* tab_d_length_ptr = &tab_d_length;
    int* tab_u_length_ptr = &tab_u_length;

    int zeros_number = customSieve(tab, tab_d, tab_u, tab_d_length_ptr, tab_u_length_ptr);

    printf("Number of zeros: %i\n", zeros_number);
    printf("tab_d:\n");
    for(int i = 0; i < tab_d_length; i++) {
        printf("%f ", tab_d[i]);
    }
    printf("\n");
    printf("tab_u:\n");
    for(int i = 0; i < tab_u_length; i++) {
        printf("%f ", tab_u[i]);
    }
    printf("\n");
    return 0;
}