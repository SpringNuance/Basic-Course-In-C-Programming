    
#include "filestats.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


/* Returns the line count in given file
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * The number of lines in file. */
int line_count(const char *filename)
{
    FILE* filePtr = fopen(filename, "r");
    if (filePtr == NULL ){
        return -1;
    }
    int count = 0;
    char line[10000];
    while (fgets(line, 10000, filePtr) != NULL) {
        count++;
    }
    
    fclose(filePtr);
    return count;
}


/* Count the number of words in the file. Word has to include at least one
 * alphabetic character, and words are separated by whitespace.
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * number of words in the file */
int word_count(const char *filename)
{
    FILE* filePtr = fopen(filename, "r");
    if (filePtr == NULL ){
        return -1;
    }
    int count = 0;
    
    /////
    int byte = fgetc(filePtr);
    while (byte != EOF){

        if (isalpha(byte)){
            count++;
            byte = fgetc(filePtr);
            while (!isspace(byte)){
                if (byte == EOF){
                    break;
                }
                byte = fgetc(filePtr);
            }
        }

        if (isspace(byte)){
            byte = fgetc(filePtr);
            while(!isalpha(byte)){
                if (byte == EOF){
                    break;
                }
                byte = fgetc(filePtr);
            }
        }
    }

    /////
    
    fclose(filePtr);
    return count;
}
