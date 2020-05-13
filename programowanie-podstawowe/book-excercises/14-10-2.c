#include<stdio.h>

int createTable(int tab[], int old[], int old_length) {
    int new_length = 0;

    for(int i = 0; i < old_length; i++) {
        if(old[i] > 100) {
            tab[new_length] = old[i];
            new_length++;
        }
    }

    return new_length;
}

int main(void) {
    int old_tab[200];
    int new_tab[200];

    for(int i = 0; i < 200; i++) {
        old_tab[i] = i;
    }

    int new_length = createTable(new_tab, old_tab, 200);

    printf("New table:\n");
    for(int i = 0; i < new_length; i++) {
        printf("%i ", new_tab[i]);
    }

    printf("\n");


}