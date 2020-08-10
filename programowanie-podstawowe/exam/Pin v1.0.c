#include<stdio.h>
#include<string.h>

int main(void) {
    const char* pin = "mypin";

    char try[50];

    int iscorrect = 0;
    while(!iscorrect) {
        printf("Input pin: ");
        scanf("%s", &try);
        // printf("%s %s", pin, try);
        if(strcmp(pin, try) == 0) {
            printf("PIN correct\n");
            iscorrect = 1;
        } else {
            printf("PIN incorrect.\n");
        }
    }

    return 0;
}