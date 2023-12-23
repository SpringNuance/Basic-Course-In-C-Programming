#include "hexread.h"
#include <stdlib.h>
#include <stdio.h>


/* Prints the given file as hexdump, at most 16 numbers per line.
 * <filename> parameter is the name of the file.
 * 
 * Returns the number of characters read
 */
int file_to_hex(const char *filename){
    FILE* filePtr = fopen(filename, "r");
    int count = 0;
    int newLine = 1;
    if (filePtr == NULL){
        return -1;
    }
    int byte = fgetc(filePtr);
    while (byte != EOF){
        count++;
        if (newLine == 16){
          printf("%2x \n", byte);
          newLine = 1;
        } else {
          printf("%2x ", byte);
          newLine++;
        }
        byte = fgetc(filePtr);
    }
    fclose(filePtr);
    return count;
}
