#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FILE *file_stream;

    const char* file_name = "kp.txt";

    if((file_stream=fopen(file_name, "w")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    } else {
        fprintf(file_stream, "Konrad\n28\nŁódź");
    }

    fclose(file_stream);

    return 0;
}