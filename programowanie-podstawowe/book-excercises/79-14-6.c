#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Struct {
    char name[50], surname[50], result[50];
};

int readFile(char *fname, FILE *fp);
int writeToFile(char *fname, FILE *fp, struct Struct);
int printThreeBest(char *fname, FILE *fp);


int main(void) {
    char *file_name = "79-14-5-biking.txt";
    FILE *fp;
    char choice='a';
    struct Struct player;
    char name[50], surname[50], result[50];
    while(choice!='e') {
        printf("Input a to add another player (e to exit):\n");
        scanf("%s", &choice);
        switch(choice) {
            case 'a':
                printf("Input name, surname and result: ");
                scanf("%s %s %s", &player.name, &player.surname, &player.result);
                writeToFile(file_name, fp, player);
                break;
            case 'e':
                break;
            default:
            break;
        }
    }

    printf("Three best players:\n");
    printThreeBest(file_name, fp);
    return 0;
}


int readFile(char *fname, FILE *fp) {
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    struct Struct player;
    while(fscanf(fp, "%s %s %s \n", &player.name, &player.surname, &player.result) == 3) {
        printf("%s %s %s \n", player.name, player.surname, player.result);
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

    fprintf(fp, "%s %s %s\n", item.name, item.surname, item.result);

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};

int printThreeBest(char *fname, FILE *fp) {
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    struct Struct best_players[3];
    strcpy(best_players[0].result, "32000");
    strcpy(best_players[1].result, "32000");
    strcpy(best_players[2].result, "32000");
    struct Struct player;
    float result;
    while(fscanf(fp, "%s %s %s \n", &player.name, &player.surname, &player.result) == 3) {
        // printf("%s %s %s \n", player.name, player.surname, player.result);
        result = strtof(player.result, NULL);
        if(result < strtof(best_players[0].result, NULL)){
            best_players[2] = best_players[1];
            best_players[1] = best_players[0];
            best_players[0] = player;
        } else {
            if (result < strtof(best_players[1].result, NULL)) {
                best_players[2] = best_players[1];
                best_players[1] = player;
            } else {
                if(result < strtof(best_players[2].result, NULL)) {
                    best_players[2] = player;
                }
            }
        }
    }

    printf("Three best results:\n");
    for(int i = 0; i < 3; i++) {
        printf("%s %s %s\n", best_players[i].name, best_players[i].surname, best_players[i].result);
    }
    
    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }

    return 0;
};