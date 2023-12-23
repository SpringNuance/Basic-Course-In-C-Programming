#include "source.h"
#include "ctype.h"

/* Count Alpha
 * Count number of alphabetic characters in the given string <str>,
 * and return the count
 */
int count_isalpha(const char *str){
    int count = 0;
    while (*str != '\0') {  
    if (isalpha(*str)){
      count++;
    }
      str++;  
    }
    return count;
}

