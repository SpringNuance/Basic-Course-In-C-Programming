#include <stdlib.h>
#include <stdio.h>

/*
Implement the following function that
processes table numbers that contains unsigned integers. The table 
ends with number 0. The function should return the largest integer in the table.
*/
unsigned int pickmax(unsigned int *numbers){
    int i = 0;
    unsigned int max = 0;
    while (numbers[i] != 0){
        if (numbers[i] > max){
            max = numbers[i];
        }
        i++;
    }
    return max;
}

// implement also the main function that tests the functionality of 
// the function you implemented above by 
// at least three different parameter combinations
int main(void){
   unsigned int array[10] = {6,7,5,8,9,2,1,4,2,0};
   printf("Biggest number is %u", pickmax(array));
}