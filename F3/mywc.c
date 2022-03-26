#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){


    if (strncmp(argv[1], "-c", 3) == 0){
        long lSize;
        FILE * file1 = fopen(argv[2], "r");

        // obtain file1 size:
        fseek (file1 , 0 , SEEK_END);
        lSize = ftell (file1);
        rewind (file1);

        printf("Characters: %d\n", lSize);

        fclose(file1);
    }
    else if (strncmp(argv[1], "-w", 3) == 0){
        long lSize;
        FILE * file1 = fopen(argv[2], "r");

        // obtain file1 size:
        fseek (file1 , 0 , SEEK_END);
        lSize = ftell (file1);
        rewind (file1);

        char *buffer = (char*) malloc (sizeof(char)*lSize);
        fread(buffer, 1, lSize, file1);

        int countWords = 0, word;

        for (int i = 1; i < lSize; i++){
            if (buffer[i] != ' ')
                word = 1;
            else{
                if (word)
                    countWords++;
                word = 0;    
            }    
        }

        printf("Words: %d\n", countWords);

        fclose(file1);
        free(buffer);
    }

    else if (strncmp(argv[1], "-l", 3) == 0){
        long lSize;
        FILE * file1 = fopen(argv[2], "r");

        // obtain file1 size:
        fseek (file1 , 0 , SEEK_END);
        lSize = ftell (file1);
        rewind (file1);

        char *buffer = (char*) malloc (sizeof(char)*lSize);
        fread(buffer, 1, lSize, file1);

        int countLines = 0;

        for (int i = 0; i < lSize; i++){
            if (buffer[i] == '\n')
                countLines++;
        }

        printf("Lines: %d\n", countLines);

        fclose(file1);
        free(buffer);
    }
    else{
        long lSize;
        FILE * file1 = fopen(argv[1], "r");

        // obtain file1 size:
        fseek (file1 , 0 , SEEK_END);
        lSize = ftell (file1);
        rewind (file1);

        printf("Characters: %d\n", lSize);

        fclose(file1);
    }



    
    

    return EXIT_SUCCESS;
}