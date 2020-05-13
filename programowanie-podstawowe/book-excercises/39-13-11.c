#include<stdio.h>
#include<stdlib.h>

struct Point {
    int x, y, z;
};

void completePoint(struct Point* point, struct Point* previous_point) {
    point->y = point->x + 2 * previous_point->x;
    point->z = 2 * (point->x + point->y * point->y);
};

struct Point createPoint(void) {
    printf("Input x coordinate of a point: ");
    int x;
    struct Point new_point;
    scanf("%i", &new_point.x);
    return new_point;
};

void printPoints(struct Point* points, int points_length) {
    printf("X[0]=%i\n", points[0].x);
    for(int i = 1; i < points_length; i++) {
        printf("X[%i]=%i  Y[%i]=%i  Z[%i]=%i\n", i, points[i].x, i, points[i].y, i, points[i].z);
    }
}

int main(void) {
    int number;
    do {
        printf("Input number of points: \n");
        scanf("%i", &number);
    } while(number < 3 || number > 11);

    struct Point* points = malloc(number * sizeof(struct Point));
    for(int i = 0; i < number; i++) {
        points[i] = createPoint();
    }

    for(int i = 1; i < number; i++) {
        completePoint(&points[i], &points[i - 1]);
    }

    printf("Points:\n");
    printPoints(points, number);

    return 0;
}