#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "dynamic-arrays-toolbox.h"

float* calculateDistances(float** points, int points_number) {
    float* distances = create1Darray(points_number);

    for(int i = 0; i < points_number; i++) {
        distances[i] = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
    }

    return distances;
}

int main(void) {
    printf("Input number of points: ");
    int points_number;
    scanf("%i", &points_number);

    float** points = create2Darray(points_number, 2);

    printf("Input coordinates of %i points:\n", points_number);
    read2Darray(points, points_number, 2);

    float* distances_from_00 = calculateDistances(points, points_number);
    printf("Distances of points from the point (0,0):\n");
    output1Darray(distances_from_00, points_number);
    return 0;
}