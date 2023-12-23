/*
Define a two dimensional 6x6 static array with name **taulu**. Value stored in each 
array index must be the product of **row** and **column** index. For example,

taulu[0][0] contains the value 0, 
taulu[2][3] contains the value 6, and 
taulu[5][5] contains the value 25.

All values are integers.

You will get points if the expected output is printed:

    0  0  0  0  0  0 
    0  1  2  3  4  5 
    0  2  4  6  8 10 
    0  3  6  9 12 15 
    0  4  8 12 16 20 
    0  5 10 15 20 25
*/

#include <stdio.h>

int main(void)
{
        // define the static array **taulu** here
    int taulu[6][6];
    for (int i = 0; i < 6; i++) {
            taulu[0][i] = 0;
    } 

    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            taulu[i][j] = taulu[i - 1][j] + j ;
    } 
    }


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%2d ", taulu[j][i]);
        }
        printf("\n");
    }
    return 0;
}