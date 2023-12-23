#include "source.h"

#include <stdlib.h>
#include <string.h>

char *mystrcat(char *dest, const char *src)
{
    dest = realloc(dest, (strlen(src) + strlen(dest) + 1) * sizeof(char));
    char *origdest = dest;
    while(*dest) {
         dest++;
    }

    while (*src) {
        *dest++ = *src++;  // Kopioi merkin ja sitten kasvattaa osoittimia
    }
    *dest = 0;

    return origdest;
}