#include <stdlib.h>
#include <stdio.h>
#include "source.h"
#include <string.h>

/* Remove C comments from the program stored in memory block <input>.
 * Returns pointer to code after removal of comments.
 * Calling code is responsible of freeing only the memory block returned by
 * the function.
 */
char *delete_comments(char *input)
{
    unsigned int n = strlen(input);
    char* afterDel = malloc(n + 1);
    unsigned int i;
    unsigned int trace;
    for (i=0, trace = 0; i < n; i++) {
        if (input[i] == '/' && input[i+1] == '*') {
            while(input[i] != '*' || input[i+1] != '/') {
                i++;
            }
                
            i++;
        } else if (input[i] == '/' && input[i+1] == '/') {
            while(input[i] != '\n'){
                i++;
            }
        } else {
            afterDel[trace] = input[i];
            trace++;
        }
    }
    free(input);
    afterDel[trace] = '\0';
    return afterDel;
}
