#include <stdio.h>

void show_table(long *a, size_t n)
{
    for (size_t i = 0; i < n; i++) {
    printf("%lu ", *(a + i));
    }
    printf("\n");
}

int main(void)
{
    long table[30] = { 3 };
    for (int i = 0; i < 29; i++){
        table[i+1] = table[i]*2;
    }

    printf("size: %lu\n", sizeof(table)); /* print array size for fun */

    /* below is one way to get the number of elements */
    // sizeof(table) is 4 * sizeof(short) == 8;
    show_table(table, sizeof(table)/sizeof(long));

    // in this case the above would be equivalent to:

    return 0;
}
