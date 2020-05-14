#include<stdio.h>
#include<math.h>

float weird_function(float alpha, int t) {
    /* I am not convinced this is the best practice, so I leave it out. C has no ecxeptions unfortunately
    I could create another function to check for correct range of t. lets do that.
    if(t < 0 || t > 8) {
        /* z is defined when t is in <0 8>, so throw something when it is not in that range 
        return t/  0;
    }
    */
    float value;

    if(t < 4) {
        value = 1 - sin(alpha);
    } else {
        if(t < 8) {
            value = 0.5 * (1 + cos(alpha));
        } else {
            value = sqrt(alpha * alpha + 1);
        }
    }

    return value;
}

int tInRange(int t) {
    return t >= 0 && t <= 8;
}


int main() {
    float alpha;
    int t;

    printf("Input parameters alpha and t: ");
    scanf("%f %i", &alpha, &t);

    if(tInRange(t)) {
        printf("Value of the function for alpha=%f and t=%i is %f\n", alpha, t, weird_function(alpha, t));
    } else {
        printf("Parameter t is out of range - needs to be in <0; 8>\n");
    }

    return 0;
}