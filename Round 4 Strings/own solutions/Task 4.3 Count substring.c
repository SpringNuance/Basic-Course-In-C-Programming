#include <string.h>
#include "source.h"



/* Count Substring
 * Count number of occurances of substring <sub> in string <str>,
 * and return the count.
 */
int num_substr(const char *str, const char *sub)
{
    int count = 0;
    char *ptr = strstr(str, sub);
    while (ptr != NULL) {  
      ptr++;
      ptr = strstr(ptr, sub);
      count++;
    }
    return count;
}

