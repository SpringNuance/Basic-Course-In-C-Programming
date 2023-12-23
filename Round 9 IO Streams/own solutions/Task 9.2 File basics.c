#include "filebasics.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/* Print given file <filename> to the standard output stream.
 * Return number of characters printed, -1 if file opening fails.
 */
int print_file_and_count(const char *filename) {
    FILE* filePtr = fopen(filename, "r");
    if (filePtr == NULL){
        return -1;
    }
    int count = 0;
    int byte = fgetc(filePtr);
    while (byte != EOF){
        count++;
        printf("%c", byte);
        byte = fgetc(filePtr);
    }

    fclose(filePtr);
    return count;
}

/* Compare two files. The function should return the first lines that differ
 * in the two files, concatenated together, separated by four dashes, on
 * different lines. If the files are equal, NULL is returned. 
 * Function stops immediately, if either one of the files end and returns NULL.
 * You can assume that lines are not longer than 1000 characters.
 */
char *difference(const char *file1, const char *file2){
    FILE* file1Ptr = fopen(file1, "r");
    FILE* file2Ptr = fopen(file2, "r");
    if (file1Ptr == NULL || file2Ptr == NULL){
        return NULL;
    }
    char firstLine[1000];
    char secondLine[1000]; 
    fgets(firstLine, 1000, file1Ptr);
    fgets(secondLine, 1000, file2Ptr);
    while (strcmp(firstLine, secondLine) == 0) {
        char * ptr1 = fgets(firstLine, 1000, file1Ptr);
        char * ptr2 = fgets(secondLine, 1000, file2Ptr);
        if (ptr1 == NULL || ptr2 == NULL){
           return NULL;
        }
    }

    char* concatenatedLine = calloc(2006, sizeof(char));
    strcpy(concatenatedLine, firstLine);
    strcat(concatenatedLine, "----\n");
    strcat(concatenatedLine, secondLine);
    
    fclose(file1Ptr);
    fclose(file2Ptr);
    return concatenatedLine;

}


