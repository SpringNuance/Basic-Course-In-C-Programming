#include <stdio.h>

unsigned int arraylen(const char *array){
  int i = 0;
  while(array[i] != 0){
      i++;
  }
  return i;
}

void countchars(const char *array, unsigned int *counts){
    unsigned int n = arraylen(array);
    for (unsigned int i=0; i< n; i++) {
        int position = (int)array[i];
        counts[position] = counts[position] + 1;
      
    }


}




