#include<stdio.h>

void monthNumberAndDays(int month_no) {
    switch(month_no) {
        case 1:
        case 3:
            printf("First quarter, 31 days.\n");
            break;
        case 5:
            printf("Second quarter, 31 days.\n");
            break;
        case 7:
        case 8:
            printf("Third quarter, 31 days.\n");
            break;
        case 10:
        case 12:
            printf("Fourth quarter, 31 days.\n");
            break;
        case 2:
            printf("First quarter, 30 days.");
            break;
        case 4:
        case 6:
            printf("Second quarter, 30 days.\n");
            break;
        case 9:
            printf("Third quarter, 30 days.\n");
            break;
        case 11:
            printf("Fourth quarter, 30 days.\n");
            break;
    }
};

int main(void) {
    int month_no;
    printf("Input month number:" );
    scanf("%i", &month_no);
    printf("Month number: %i. ", month_no);
    monthNumberAndDays(month_no);
    return 0;
}