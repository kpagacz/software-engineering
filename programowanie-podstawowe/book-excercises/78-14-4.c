#include<stdio.h>
#include<stdlib.h>

int readTemperatures(char *fname, FILE *fp);
int writeTemperatureToFile(char *fname, FILE *fp, float temp);
float calculateAvgTemp(char *fname, FILE *fp);


int main(void) {
    char *file_name = "78-14-4-temps.txt";
    FILE *fp;
    char choice='a';
    float temp;
    while(choice!='e') {
        printf("Input a to add another temperature (e to exit):\n");
        scanf("%s", &choice);
        switch(choice) {
            case 'a':
                printf("Input a temperature measurement: ");
                scanf("%f", &temp);
                writeTemperatureToFile(file_name, fp, temp);
                break;
            case 'e':
                break;
            default:
            break;
        }
    }

    printf("Average temperature: %.2f", calculateAvgTemp(file_name, fp));
    return 0;
}


int readTemperatures(char *fname, FILE *fp) {
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    float temp;
    while(fscanf(fp, "%f\n", &temp) == 1) {
        printf("%f\n", temp);
    }

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};

int writeTemperatureToFile(char *fname, FILE *fp, float temp) {
    if((fp=fopen(fname, "a")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    fprintf(fp, "%f\n", temp);

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};

float calculateAvgTemp(char *fname, FILE *fp) {
    float sum=0;
    int counter=0;
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open the file.");
        exit(1);
    }

    float temp;
    while(fscanf(fp, "%f\n", &temp) == 1) {
        sum += temp;
        counter++;
    }

    return sum / counter;
};