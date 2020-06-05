#include<stdlib.h>
#include<stdio.h>
#include<time.h>

struct Struct {
    int number;
};

int readFile(char *fname, FILE *fp);
int writeToFile(char *fname, FILE *fp, struct Struct);
int createRandomNumbers(char *fname, FILE *fp);
int outputFileAtPosition(char *fname, FILE *fp, int position);

int main(void) {
    char *file_name = "80-14-5-random-numbers";
    FILE *fp;

    createRandomNumbers(file_name, fp);

    readFile(file_name, fp);

    int position;
    printf("Input a position. Number at this position will be printed out on the screen: ");
    scanf("%d", &position);

    outputFileAtPosition(file_name, fp, position);

    return 0;
}


int readFile(char *fname, FILE *fp) {
    if((fp=fopen(fname, "rb")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    struct Struct item;
    while(fread(&item.number, sizeof(int), 1, fp)== 1) {
        printf("%d\n", item.number);
    }

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};

int writeToFile(char *fname, FILE *fp, struct Struct item) {
    if((fp=fopen(fname, "ab")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    fwrite(&item.number, sizeof(int), 1, fp);

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};

int createRandomNumbers(char *fname, FILE *fp){
    int N;
    printf("Input number of random samples: ");
    scanf("%d", &N);

    srand(time(NULL));

    FILE *truncate = fopen(fname, "wb");
    fclose(truncate);

    struct Struct item;
    for(int i = 0; i < N; i++) {
        item.number = rand();
        writeToFile(fname, fp, item);
    }

};

int outputFileAtPosition(char *fname, FILE *fp, int position){
    if((fp=fopen(fname, "rb")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    long offset = position * (sizeof(int));

    if(fseek(fp, offset, SEEK_SET)!=0){
        printf("Could not seek the position.");
        exit(3);
    }

    int number;
    fread(&number, sizeof(int), 1, fp);
    printf("Number at this positions: %d\n", number);

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};
