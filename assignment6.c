#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>

int main(int argc, char * argv[]){
    int ch;
    char *buffer;
    size_t bsize = 128;
    size_t characters;
    char *dirBuffer;
    FILE *fp;

    while ((ch = getopt(argc, argv, "p")) != -1)     //Read command.
    {
        switch (ch)
        {
            case 'p':        //if -p, change boolean to 1.

                //pflag = 1;

                break;

            case '?':       //if option not included, print out error message.
                printf("Unknown option: %c\n",(char)optopt);
                exit(1);

        }

    }

     buffer = (char *)malloc(bsize * sizeof(char));

        if (buffer == NULL)
        {
            perror("Allocate buffer failed\n");
            exit(1);
        }

        printf("Go ahead: ");

        characters = getline(&buffer, &bsize, stdin);

    for (int i = optind; i < argc; i++)     //for each user input
    {
        fp = fopen(argv[i], "w");

        if(fp == NULL) 
        {
        printf("file can't be opened\n");
        exit(1);
        }

        fputs(buffer, fp);

        fclose(fp);

        /*int j = 0;          //set j

        memset(&dirBuffer[0], 0, sizeof(dirBuffer));        //set dirBuffer to NULL

        if (mkdir(argv[i], 0777) == -1)         //if makdir return false
        {
            if(errno != 2)
            {
                printf("Illegal operation, please check your syntax.\n" );
            }

            if(pflag == 1)
            {

                strcpy (buffer, argv[i]);           //copy user input dir location or name to buffer

                for (int k = 0; k <= strlen(buffer); k++)   //for each character in buffer
                {

                    if(buffer[k] == '/'|| buffer[k] == '\0')    //if the character is / or end of line
                    {

                        if(access(dirBuffer, 0) != 0)   //if dirBuffer does not exist
                        {
                            mkdir(dirBuffer, 0777);     //make dirBuffer directory
                        }

                        dirBuffer[j] = '/';         //set this character in dirBuffer to /

                        j++;                        //go to next character

                    }
                    else
                    {
                        dirBuffer[j] = buffer[k];   //set the kth character in buffer to jth character in dirBuffer

                        j++;                        //go to next character
                    }
                }
            }
        }*/
    }


    return 0;
}
