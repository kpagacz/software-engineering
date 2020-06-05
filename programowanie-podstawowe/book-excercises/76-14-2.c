#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Worker{
    char name[30], surname[30];
    int hours, bonus;
    float rate;
    float wage;
};

int writeWorkerToFile(char fname[30], FILE *fp, struct Worker worker);
int readWorkersFromFile(char fname[30], FILE *fp);


int main(void) {
    char name[30], surname[30];
    int hours, bonus;
    float rate;
    float wage;
    // printf("%s %s %d %f %d\n", name, surname, hours, rate, bonus);
    char *file_name = "76-14-2-worker.txt";
    FILE *fp;

    char choice = 'c';
    while(choice!='e') {
        struct Worker worker;
        printf("Input a to add another worker!\n");
        scanf(" %c", &choice);
        switch(choice) {
            case 'a':
                printf("Input worker's name, surname, his hours, rate, bonus(in percents): \n");
                scanf("%s %s %d %f %d", &name, &surname, &hours, &rate, &bonus);
                strcpy(worker.name, name);
                strcpy(worker.surname, surname);
                worker.hours = hours;
                worker.bonus = bonus;
                worker.rate = rate;
                worker.wage = rate * hours / 100 * (1 + bonus);

                writeWorkerToFile(file_name, fp, worker);
                break;

            case 'e':
                break;

            default:
                printf("Wrong input!\n");
                break;
        }
    }

    readWorkersFromFile(file_name, fp);

    return 0;
}


int writeWorkerToFile(char fname[30], FILE *fp, struct Worker worker){
    if((fp=fopen(fname, "a")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    fprintf(fp, "%s %s %d %f %d %f\n", worker.name, worker.surname, worker.hours, worker.rate, worker.bonus, worker.wage);

    if(fclose(fp) != 0) {
        printf("Cannot close the file.\n");
        exit(2);
    }

    return 0;
};

int readWorkersFromFile(char fname[30], FILE *fp){
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    float threshold;
    printf("Input threshold. Workers with wage above the threshold will be printed: ");
    scanf("%f", &threshold);

    char name[30], surname[30];
    int hours, bonus;
    float rate;
    float wage;    

    printf("%f\n", threshold);
    char line[200];
    while(fgets(line, 200, fp) != NULL) {
        sscanf(line, "%s %s %d %f %d %f\n", &name, &surname, &hours, &rate, &bonus, &wage);
        // printf(" %.2f %.2f\n", threshold, wage);
        if(wage > threshold) {
            printf("%s %s %d %f %d %f\n", name, surname, hours, rate, bonus, wage);
        }
    }
};
