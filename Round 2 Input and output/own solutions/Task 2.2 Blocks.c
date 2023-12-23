#include <stdio.h>

int main(void)
{
    int a = 1;
    a = a + 1;
    
        int b = 6;
        b = b + 1;
    
    a = a + b;
    printf("a: %d", a);
    return 0;
}