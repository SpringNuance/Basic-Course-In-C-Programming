#include "source.h"

#include <stdio.h>
#include <math.h>

void simple_multiply(void)
{
    int n1, n2;
    int success = scanf("%d %d", &n1, &n2);
    if (success != 2) { return;} 
    int res = n1 * n2;
    printf("%d * %d = %d\n", n1, n2, res);
}

void simple_math(void)
{
    float n1, n2;
    char oper;
    int success = scanf("%f %c %f", &n1, &oper, &n2);
    if (success != 3){
        printf("ERR\n");
        return;
    }
    switch (oper){
        case '+':
        printf("%.1f\n", n1 + n2);
        break;
        case '-':
        printf("%.1f\n", n1 - n2);
        break;
        case '*':
        printf("%.1f\n", n1 * n2);
        break;
        case '/': 
        printf("%.1f\n", n1 / n2);
        break;
        default:
        printf("ERR\n");
        break;
    }
    
}




