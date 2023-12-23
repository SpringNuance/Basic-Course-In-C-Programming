#include <stdlib.h>
#include <stdio.h>

/*
Implement the following function that
concatenates string src after string dest. The function does not allocate 
memory, but it assumes that the calling function arranges the memory 
somehow (as with the original strcat function). The function 
returns pointer to the beginning of the string. In this task you must 
not use the strcat function that is defined in string.h header.
*/
char* mystrcat(char *dest, const char *src){
  int i=0,j=0;
  while(dest[i] != '\0') i++;
  while(src[j] != '\0') {
    dest[i] = src[j];
    j++;
    i++;
  }
  dest[i]='\0';
  return dest;
    
}

// implement also the main function that tests the functionality of 
// the function you implemented above by 
// at least three different parameter combinations
int main(void){
    char str1[8] = "hello";
    char str2[20] = "world";
    printf("%s", mystrcat(str1, str2));
    return 0;
}