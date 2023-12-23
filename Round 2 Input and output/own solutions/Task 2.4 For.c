#include <stdio.h>

int main(void)
{
    int a;
    for (a = 8; a >= 0; a--) {
        if (a % 2 == 1)
            continue;
        printf("value of a is now %d\n", a);
    }

    return 0;
}
