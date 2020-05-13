#include<stdio.h>
#include<stdlib.h>

/* I don't get this task. Besides the fact that it can be done without any tables
it does not specify the input at all */

float* create1Darray(int length) {
    float* arr = (float*) malloc(sizeof(float) * length);
    return arr;
}

void read1Darray(float* array, int length) {
    printf("Input array elements: ");
    for(int i = 0; i < length; i++) {
        scanf("%f", array + i);
    }
}

int main(void) {
    int players;
    printf("Input number of players: ");
    scanf("%i", &players);

    float* player_times = create1Darray(players);
    read1Darray(player_times, players);

    float min = __FLT_MAX__;
    int min_index = 0;

    for(int i = 0; i < players; i++) {
        if(player_times[i] < min) {
            min = player_times[i];
            min_index = i;
        }
    }

    printf("Best time: %.2f Player number: %i", player_times[min_index], min_index);
    return 0;
}
