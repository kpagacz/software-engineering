#include<stdio.h>
#include<stdlib.h>

int readFile(char *fname, FILE *fp);
int copyEveryThirdChar(char *fname1, char *fname2, FILE *fp1, FILE *fp2);

int main(void) {
    char *file_name1 = "82-14-8-file1.txt";
    char *file_name2 = "82-14-8-file2.txt";

    FILE *fp1, *fp2;

    printf("First file:\n");
    readFile(file_name1, fp1);

    printf("\n--------------------\n");

    // copying
    copyEveryThirdChar(file_name1, file_name2, fp1, fp2);

    printf("Second file:\n");
    readFile(file_name2, fp1);

    return 0;
}

int readFile(char *fname, FILE *fp){
    if((fp=fopen(fname, "r")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    int c;
    while((c=getc(fp)) != EOF) {
        putc(c, stdout);
    }

    if(fclose(fp) != 0) {
        printf("Could not close the file.");
        exit(2);
    }
};

int copyEveryThirdChar(char *fname1, char *fname2, FILE *fp1, FILE *fp2){
    if((fp1=fopen(fname1, "r")) == NULL || (fp2=fopen(fname2, "w")) == NULL) {
        printf("Could not open file.");
        exit(1);
    }

    int counter = 3;
    int c;
    while((c=getc(fp1)) != EOF) {
        if(counter > 1) {
            counter--;
            continue;
        } else {
            putc(c, fp2);
            counter = 3;
        }
    }


    if(fclose(fp1) != 0 || fclose(fp2) != 0) {
        printf("Could not close a file.");
        exit(2);
    }
};
