#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size)
{
    if (size == 0) {
        return;
    }
    for (unsigned int a = 0; a <= size-1; a++) {
        for (unsigned int b = 2; b <= size - a; b++){
            printf(".");
        }
        for (unsigned int c = 0; c <= a; c++){
            printf("#");
        }
        printf("\n");
    }
}
