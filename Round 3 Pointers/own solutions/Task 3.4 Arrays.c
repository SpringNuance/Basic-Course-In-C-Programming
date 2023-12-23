#include <stdio.h>
#include "source.h"


/* Array Sum
 * Calculate the sum of integers in array starting at address <array>.
 * There will be <count> elements in array. Return the sum as return value.
 */
int array_sum(int *array, int count)
{
    int *intPtr;
    intPtr = array;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum = sum + *intPtr;
        intPtr++;  // move the pointer to the next element
    }
    return sum;
}

/* Array Reader */
/* Parameters:
 * vals: array to be filled
 * n: maximum size of array
 * returns: number of values read */
unsigned int array_reader(int *vals, int n)
{
    unsigned int calls = 0;
    for (int i = 0; i < n; i++){
        int a;
        int success = scanf("%d",&a);
        if(success == 1) {
           *(vals + i) = a;
           calls++; 
           } else {
              return calls; 
           }
    } 
    return calls;
}
