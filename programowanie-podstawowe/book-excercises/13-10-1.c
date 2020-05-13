#include<stdio.h>
#include<limits.h>

int isThereMean(float tab[], int length) {
    float min_ = __FLT_MAX__, max_ = __FLT_MIN__;
    for(int i = 0; i < length; i++) {
        if(tab[i] < min_) min_ = tab[i];
        if(tab[i] > max_) max_ = tab[i];
    }

    float avg = 0.5 * (min_ + max_);

    for(int i = 0; i < length; i++) {
        if(tab[i] == avg) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int length;
    printf("Input length and elements of array (max 10000 elements): ");
    scanf("%i", &length);

    float tab[10000];

    for(int i = 0; i < length; i++) {
        scanf("%f", &tab[i]);
    }

    int res = isThereMean(tab, length);
    res ? printf("One of the elmenets is the average of min and max\n") :
             printf("There is no element with value equal to average between min and max\n");
    return 0;
}