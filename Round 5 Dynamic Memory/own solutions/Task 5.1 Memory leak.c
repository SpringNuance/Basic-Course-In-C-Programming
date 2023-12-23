#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_string(const char *str)
{
    unsigned int len = strlen(str);
    char *newstr = malloc(len + 1);
    unsigned int i;
    for (i = 0; i < len; i++) {
	    newstr[i] = str[len - i - 1];
    }
    newstr[i] = 0;
    return newstr;
}

int main(void)
{
    char *rev;
    rev = reverse_string("Heippa vaan");
    printf("%s\n", rev);
    free(rev);

    rev = reverse_string("Moikka vaan");
    printf("%s\n", rev);
    free(rev);

    return 0;
}