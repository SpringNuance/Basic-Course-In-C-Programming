#include "source.h"
#include <stdio.h>
#include <stddef.h>

/* Print string */
/* Parameters:
 * s: string to be printed */
void qstr_print(const char *s) {
    for(int i=0; s[i]!='?'; i++)
        printf("%c", s[i]);
}

/* String length */
/* Parameters:
 * s: string to be evaluated
 * Returns: length of the string */
unsigned int qstr_length(const char *s) {
    int n=0;
    for( ; s[n] != '?'; n++);
    return n;
}

/* String cat */
/* Parameters:
 * dst: buffer to which the new string is appended
 * src: string to be appended
 * Returns: Number of characters in the new string */
int qstr_cat(char* dst, const char* src) {
    int i=0;
    for( ; dst[i] != '?'; i++);

    for(unsigned int j=0; j <= qstr_length(src); j++, i++) {
        dst[i] = src[j];
    }

    return qstr_length(dst);
}

/* String strstr */
const char* qstr_strstr(const char* str1, const char* str2) {
    for(unsigned int i=0; i<qstr_length(str1); i++) {
        if(str1[i] == str2[0]) { // First character match
            for(int j=i, k=0; str1[j]==str2[k]; ) {
                k++;
                j++;

                if(str2[k] == '?') {
                    // Found substring!
                    return &str1[i];
                }
            }
        }
    }

    return NULL;
}
