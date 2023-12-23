
#include "source.h"


/* Selection sort */
/* Parameters:
 * start: start of an array
 * size: length of an array
 */
void sort(int *start, int size)
{
    int idx;
    for (int i = 0; i < size - 1; i++){
        idx = i;
        for (int j = i + 1; j < size; j++){
            if (start[j] < start[idx]){
                idx = j;
            }
        }
        int record = start[idx];
        start[idx] = start[i];
        start[i] = record;
    }
}
