#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    
    long lSize;
    FILE * file1 = fopen(argv[1], "r");
    FILE * file2 = fopen(argv[2], "w");

    // obtain file1 size:
    fseek (file1 , 0 , SEEK_END);
    lSize = ftell (file1);
    rewind (file1);

    char *buffer = (char*) malloc (sizeof(char)*lSize);
    fread(buffer, 1, lSize, file1);
    fwrite(buffer, 1, lSize, file2);


    free(buffer);
    fclose(file1);
    fclose(file2);

    return EXIT_SUCCESS;
}