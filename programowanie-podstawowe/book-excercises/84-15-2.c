#include<stdio.h>

#define SQUARE(x) (x)*(x)
#define ABS(x) (x) >= 0 ? (x) : (x) * (-1)

int main(void){
    int x=5, y=-5;

    printf("%d %d %d %d %d %d\n", SQUARE(x), SQUARE(x+1), SQUARE(2*x), SQUARE(y), SQUARE(y+1), SQUARE(2*y));
    printf("%d %d %d %d %d %d", ABS(x), ABS(x+1), ABS(2*x), ABS(y), ABS(y+1), ABS(2*y));
    

    return 0;
}