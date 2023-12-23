#include "source.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ascii_chart(char min, char max)
{
    int i = 1;
            for ( ;min <= max; min++){
                printf("%3d ", min);
                printf("0x%02x ", min);
                if (isprint(min) == 0){
                    printf("?");
                } else {
                    printf("%c", min);
                }
                if (i % 4 != 0){
                    printf("\t");
                } else {
                    printf("\n");
                }
                i = i + 1;
            }
       
}
