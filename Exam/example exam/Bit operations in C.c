#include <stdlib.h>
#include <stdio.h>

/*
Implement the following function that
goes through n bytes starting from address buffer, and sets bit number 
bit in each of the bytes. The most significant bit is numbered 7, and 
the least significant bit is numbered 0.
*/
void set_bit(unsigned char *buffer, unsigned int n, int bit){
   for (unsigned int i = 0; i < n; i++){
       buffer[i] |= (1 << bit);
   }
}

// implement also the main function that tests the functionality of 
// the function you implemented above by 
// at least three different parameter combinations
int main(void){
    unsigned char buffer[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    set_bit(buffer, 17, 3);
    for (unsigned int i = 0; i < 17; i++){
       printf("%u ", buffer[i]);
   }

    return 0;
}