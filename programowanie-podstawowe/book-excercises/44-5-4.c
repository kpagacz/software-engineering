#include<stdio.h>

int isLuckyTicket(char ticket[7]) {
    int sum_first_half, sum_second_half;
    sum_first_half = ticket[0] + ticket[1] + ticket[2];
    sum_second_half = ticket[3] + ticket[4] + ticket[5];

    return sum_first_half == sum_second_half;
}

int main(void) {
    char ticket[7];
    printf("Input 6digits of the ticket number: ");
    scanf("%s", &ticket);

    isLuckyTicket(ticket) ? printf("Ticket is lucky!\n") : printf("Ticket is not lucky :(\n");
    return 0;
}