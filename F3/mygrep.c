#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char *string = (char*) malloc (sizeof(char)*64);
    strcpy(string, argv[1]);
    
    long lSize;
    FILE * file = fopen(argv[2], "r");

    // obtain file1 size:
    fseek (file , 0 , SEEK_END);
    lSize = ftell (file);
    rewind (file);

    char *buffer = (char*) malloc (sizeof(char)*lSize);
    fread(buffer, 1, lSize, file);

    int line = 1, column = 1;

    for (int i = 0; i <(strlen(buffer)-strlen(string)+1); i++){
        if (strncmp(buffer + i, string, strlen(string)) == 0){
            printf("[%d:%d]\n", line, column);
        }
        if (buffer[i] == '\n'){
            line++;
            column=1;
        }    
        column++;    
    }

    free(buffer);
    free(string);
    fclose(file);


    return EXIT_SUCCESS;
}