#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Struct {
    char name[50], country[50];
    int amount;
};

int readFile(char *fname, FILE *fp);
int writeToFile(char *fname, FILE *fp, struct Struct);
int infoItem(char *fname, FILE *fp, char *item_name);


int main(void) {
    char *file_name = "81-14-7-items.txt";
    FILE *fp;
    char choice='a';
    struct Struct item;
    char name[50], country[50];
    int amount;
    while(choice!='e') {
        printf("Input a to add another item (e to exit):\n");
        scanf("%s", &choice);
        switch(choice) {
            case 'a':
                printf("Input name, country and amount: ");
                scanf("%s %s %d", &item.name, &item.country, &item.amount);
                writeToFile(file_name, fp, item);
                break;
            case 'e':
                break;
            default:
            break;
        }
    }

    // read file
    printf("Items in the file:\n");
    readFile(file_name, fp);

    // item info
    char item_name[50];
    printf("Input name of the item you want to know more about: ");
    scanf("%s \n", &item_name);

    infoItem(file_name, fp, item_name);

    return 0;
}


int readFile(char *fname, FILE *fp) {
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    struct Struct item;
    while(fscanf(fp, "%s %s %d\n", &item.name, &item.country, &item.amount) == 3) {
        printf("%s %s %d \n", item.name, item.country, item.amount);
    }

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};

int writeToFile(char *fname, FILE *fp, struct Struct item) {
    if((fp=fopen(fname, "a")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    fprintf(fp, "%s %s %d\n", item.name, item.country, item.amount);

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};

int infoItem(char *fname, FILE *fp, char *item_name){
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    struct Struct item;
    int sum = 0;
    while(fscanf(fp, "%s %s %d\n", &item.name, &item.country, &item.amount) == 3) {
        if(strcmp(item_name, item.name)) {
            sum += item.amount;
            printf("%s %s %d\n", item.name, item.country, item.amount);
        }
    }

    printf("Total amount: %d", sum);

    if(fclose(fp) != 0) {
        printf("could not close the file");
        exit(2);
    }
    return 0;
};