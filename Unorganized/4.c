#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <time.h>

#include <pthread.h>
#include <semaphore.h>
#define MAX_STR 100
#define OUTPUT_FILE_SIZE 10
int maxThreads = 3;
bool verbose = true;
# define getName(var, str)  sprintf(str, "%s", #var)

//prototype
long file_size(char *name);


int main()
{


    char fileName[] = "testFile.txt";

    FILE* pInputFile;               //unique pointer to file
    FILE* pOutputFile[maxThreads];  //unique pointer to file
    char outputFiles[maxThreads][OUTPUT_FILE_SIZE];

    char localWord[MAX_STR];        //localWord currently being searched
    int localCount = 0;             //local counter

    char section[maxThreads];

    /*** Initialize Global Tables ***/
    memset(section, 0, sizeof(section));
    memset(outputFiles, 0, sizeof(outputFiles));

    /*
    * Open Files
    */
    // input file
    if ((pInputFile = fopen(fileName, "r") ) == NULL) {

        /* Print Error Message */
        fprintf(stderr,
                "Unable to open file \'%s\'\n[%d]: %s\n",
                fileName, errno, strerror(errno));
        fflush(stderr);

        exit (-1);
    }

    ///get output file names
    for(int i = 0 ; i < maxThreads; i++){
        char threadFile[OUTPUT_FILE_SIZE];
        memset(threadFile, 0, sizeof(threadFile));

        sprintf(threadFile, "%d.txt", i);

        //open file
        if ((pOutputFile[i] = fopen(threadFile, "a+") ) == NULL) {

            /* Print Error Message */
            fprintf(stderr,
                    "Unable to open file \'%s\'\n[%d]: %s\n",
                    fileName, errno, strerror(errno));
            fflush(stderr);

            exit (-1);
        }
        memcpy(outputFiles[i], threadFile, strlen(threadFile));
    }

    /*
     * Parse File
     */
    int i = 0;
    while (fscanf(pInputFile, "%s", localWord) == 1) {       //while still file data

        /* Clean Text Formatting */
        //TrimRight(localWord, "\t\n\v\f\r .,!?:;-""'");       //trim excess char (right)
        //TrimLeft(localWord, "\t\n\v\f\r -");                 //trim excess char (left)

        //if(!caseSensitive){                                         //if not case-sensitive
            //ChangeToLower(localWord);                                //change to lowercase
        //}

        fputs(localWord, pOutputFile[i]);
        fputs(" ", pOutputFile[i]);

        i = (i+1)%maxThreads;

    }


    /*
    * Close Files
    */
    // input file
    fclose(pInputFile);

    //output files //MAKE SURE AFTER THREADS USED
    for(int i = 0 ; i < maxThreads; i++){
        fclose(pOutputFile[i]);
        if (remove(outputFiles[i]) == 0 && verbose == true){
            printf("Temp File %s Deleted successfully", outputFiles[i]);
        }

    }


    return 0;
}

long file_size(char *name)
{
    FILE *fp = fopen(name, "rb"); //must be binary read to get bytes

    long size=-1;
    if(fp)
    {
        fseek (fp, 0, SEEK_END);
        size = ftell(fp)+1;
        fclose(fp);
    }
    return size;
}