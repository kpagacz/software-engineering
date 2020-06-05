#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Worker{
    char name[30], surname[30];
    int hours, bonus;
    float rate;
    float wage;
};

int readWorkerFile(char fname[30], FILE *fp, struct Worker *worker);
int writeWorkerToFile(char fname[30], FILE *fp, struct Worker worker);


int main(void) {
    char name[30], surname[30];
    int hours, bonus;
    float rate;
    float wage;

    printf("Input worker's name, surname, his hours, rate, bonus(in percents): ");
    scanf("%s %s %d %f %d", &name, &surname, &hours, &rate, &bonus);
    // printf("%s %s %d %f %d\n", name, surname, hours, rate, bonus);

    struct Worker worker;
    strcpy(worker.name, name);
    strcpy(worker.surname, surname);
    worker.hours = hours;
    worker.bonus = bonus;
    worker.rate = rate;
    worker.wage = rate * hours / 100 * (1 + bonus);

    FILE *fp;
    char *file_name = "75-14-1-worker.txt";
    writeWorkerToFile(file_name, fp, worker);

    struct Worker worker2;
    readWorkerFile(file_name, fp, &worker2);

    printf("Read worker: %s %s %d %f %d %f\n", worker2.name, worker2.surname, worker2.hours, worker2.rate, worker2.bonus, worker2.wage);
    
    return 0;
}

int readWorkerFile(char fname[30], FILE *fp, struct Worker *worker) {
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    fscanf(fp, "%s %s %d %f %d %f", &worker->name, &worker->surname, &worker->hours, &worker->rate, &worker->bonus, &worker->wage);

    if(fclose(fp) != 0) {
        printf("Could not close the file.\n");
        exit(2);
    }

    return 0;
};


int writeWorkerToFile(char fname[30], FILE *fp, struct Worker worker){
    if((fp=fopen(fname, "w")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    fprintf(fp, "%s %s %d %f %d %f", worker.name, worker.surname, worker.hours, worker.rate, worker.bonus, worker.wage);

    if(fclose(fp) != 0) {
        printf("Cannot close the file.\n");
        exit(2);
    }

    return 0;
};

