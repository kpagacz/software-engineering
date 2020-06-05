#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Item{
    char author[50], title[50];
};

int writeitemToFile(char fname[30], FILE *fp, struct Item item);
int readitemsFromFile(char fname[30], FILE *fp);
int printAuthorItems(char fname[30], FILE *fp, char author_to_find[50]);

int main(void) {
    char author[50], title[50];
    // printf("%s %s %d %f %d\n", name, surname, hours, rate, bonus);
    char *file_name = "77-14-2-items.txt";
    FILE *fp;

    char choice = 'c';
    while(choice!='e') {
        struct Item item;
        printf("Input a to add another item! (e to end)\n");
        scanf(" %c", &choice);
        switch(choice) {
            case 'a':
                printf("Input item's author and title: \n");
                scanf("%s %s", &author, &title);
                strcpy(item.author, author);
                strcpy(item.title, title);

                writeitemToFile(file_name, fp, item);
                break;

            case 'e':
                break;

            default:
                printf("Wrong input!\n");
                break;
        }
    }

    char author_to_find[50];
    printf("Input author name. Their work will be printed out on the screen.\n");
    scanf("%s", &author_to_find);

    printAuthorItems(file_name, fp, author_to_find);

    return 0;
}


int writeitemToFile(char fname[30], FILE *fp, struct Item item){
    if((fp=fopen(fname, "a")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    fprintf(fp, "%s %s\n", item.author, item.title);

    if(fclose(fp) != 0) {
        printf("Cannot close the file.\n");
        exit(2);
    }

    return 0;
};

int readitemsFromFile(char fname[30], FILE *fp){
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    char author[50], title[50];

    char line[200];
    while(fgets(line, 200, fp) != NULL) {
        sscanf(line, "%s %s\n", &author, &title);
        printf("%s %s\n", author, title);
    }
};


int printAuthorItems(char fname[30], FILE *fp, char author_to_print[50]){
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    char line[200];
    char author[50], title[50];
    while(fgets(line, 200, fp) != NULL) {
        sscanf(line, "%s %s\n", &author, &title);
        if(strcmp(author, author_to_print) == 0) {
            printf("%s %s\n", author, title);
        }
    }

    if(fclose(fp) != 0) {
        printf("Could not close the file.\n");
        exit(2);
    }
};
