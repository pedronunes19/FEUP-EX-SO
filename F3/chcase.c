#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int u = 0, l = 0;
    for (int i = 1; i<argc; i++){
        if (strncmp(argv[i], "-u", 3) == 0){
            u = 1;
            l = 0;
            continue;
        }
        if (strncmp(argv[i], "-l", 3) == 0){
            u = 0;
            l = 1;
            continue;
        }
        long lSize;
        FILE * file = fopen(argv[i], "r");

        // obtain file size:
        fseek (file , 0 , SEEK_END);
        lSize = ftell (file);
        rewind (file);

        char *buffer = (char*) malloc (sizeof(char)*lSize);
        fread(buffer, 1, lSize, file);
        if (u){
            for (int k = 0; k < strlen(buffer); k++)
                buffer[k] = toupper(buffer[k]);
        } 
        if (l){
            for (int k = 0; k < strlen(buffer); k++)
                buffer[k] = tolower(buffer[k]);
        }
        printf("%s", buffer);
        free(buffer);
        fclose(file);
    }
    return EXIT_SUCCESS;
}