#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Number of needed arguments is 2.\n");
        exit(1);
    }

    FILE *file_from, *file_to;

    if((file_from=fopen(argv[1], "r")) == NULL || (file_to=fopen(argv[2], "w")) == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    char single_char = fgetc(file_from);
    while(single_char != EOF) {
        fputc(single_char, file_to);
        single_char = fgetc(file_from);
    }

    printf("Copied content of %s to %s", argv[1], argv[2]);

    fclose(file_from);
    fclose(file_to);

    return 0;
}