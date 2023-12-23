#include <stdlib.h>
#include <stdio.h>
#include "source.h"
#include <string.h>

int* join_arrays(unsigned int n1, const int *a1,
		         unsigned int n2, const int *a2,
		         unsigned int n3, const int *a3)
{
    int* table;
	int s = sizeof(int);
	table = malloc((n1 + n2 + n3) * sizeof(int));
	int* origin = table;
	memcpy(table, a1, n1*s);
	table = table + n1;
	memcpy(table, a2, n2*s);
	table = table + n2;
	memcpy(table, a3, n3*s);
	return origin;
}
