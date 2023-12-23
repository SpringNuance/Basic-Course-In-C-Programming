#include "stringsplit.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Split string by another string, return split parts + NULL in array.
 *
 * Parameters: 
 *  str: the string to split
 *  split: the string to split str with
 *
 * Returns:
 *  A dynamically reserved array of dynamically reserved string parts.
 *
 * For example called with "Test string split" and " ",
 * returns ["Test", "string", "split", NULL].
 * Or called with "Another - test" and " - ",
 * returns ["Another", "test", NULL].
 */


char** split_string(const char* str, const char* split) {
    char** arr = malloc(sizeof(char*));
    int nSplit = strlen(split);
    int sizePointer = 0;
    arr[sizePointer] = NULL;
    char* currentIndex = strstr(str, split);
    while (currentIndex != NULL) {
        arr = realloc(arr, (sizePointer + 2) * sizeof(char*));
        arr[sizePointer + 1] = NULL;
        int wordLength = currentIndex - str;
        arr[sizePointer] = calloc(wordLength + 1,sizeof(char));
        strncpy(arr[sizePointer], str, wordLength);
        str = currentIndex + nSplit;
        sizePointer++;
        currentIndex = strstr(str, split);
    }
    int wordLength = strlen(str);
    arr = realloc(arr, (sizePointer + 2) * sizeof(char*));
    arr[sizePointer] = calloc(wordLength + 1, sizeof(char));
    strncpy(arr[sizePointer], str, wordLength);
    arr[sizePointer + 1] = NULL;
    return arr;
}


void print_split_string(char **split_string) {
    int i = 0;
    while (split_string[i] != NULL) {
     printf("%s\n", split_string[i]);
     i++;
    }
}

void free_split_string(char **split_string) {
    for(int i=0; split_string[i]!=NULL; i++) {
        free(split_string[i]);
    }

    free(split_string);

}



