#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    for (int i = 1; i<argc; i++){
        long lSize;
        FILE * file = fopen(argv[i], "r");

        // obtain file size:
        fseek (file , 0 , SEEK_END);
        lSize = ftell (file);
        rewind (file);

        char *buffer = (char*) malloc (sizeof(char)*lSize);
        fread(buffer, 1, lSize, file);
        printf("%s", buffer);
        free(buffer);
        fclose(file);
    }
    return EXIT_SUCCESS;
}