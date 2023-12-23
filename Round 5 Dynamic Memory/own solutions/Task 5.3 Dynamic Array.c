#include <stdlib.h>
#include <stdio.h>
#include "source.h"

/* Dynamic Array Reader */
/* Parameters:
 * n: Number of values to be read
 * 
 * Returns: pointer to the dynamically allocated array
 */
int *create_dyn_array(unsigned int n)
{
  int *table;
  table = calloc(n, sizeof(int));
  int *origin = table;
  unsigned int i;
    for (i = 0; i < n; i++) {
        int a = scanf("%d", &table[i]);
        if (a != 1) return origin;
    }
    return origin;
}

/* Add to array */
/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 * 
 * Returns: pointer to the allocated array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
  arr = realloc(arr, (num + 1) * sizeof(int));
  arr[num] = newval;
  return arr;
}
