#include <stdio.h>

int main(void) {
    int varA = -50;
    unsigned char varB = 200;
    unsigned int varB2 = 500;  // Error, exceeds the value range
    int varC = 0;  // ok, but initial value is unknown
    long varD = 100000;

    /* Output the above values */
    printf("%d  %u  %u  %d  %ld\n", varA, varB, varB2, varC, varD);

    return 0;
}