#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *pwd = (char *) malloc(128*sizeof(char));
    getcwd(pwd, 128);
    if (pwd == NULL){
        printf("Couldn't print the path to current directory\n");
    }
    printf("%s\n", pwd);
    free(pwd);

    return EXIT_SUCCESS;
}