#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>

int main(){
    char *buffer;
    size_t bsize = 128;
    size_t characters;
    char *dirBuffer;

    buffer = (char *)malloc(bsize * sizeof(char));
    if (buffer == NULL)
    {
        perror("Allocate buffer failed\n");
        exit(1);
    }

    printf("Go ahead: ");

    characters = getline(&buffer, &bsize, stdin);

    printf("%s\n", buffer);


    return 0;
}
