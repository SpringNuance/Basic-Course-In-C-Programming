/*
In this task, you are supposed to implement two functions that are responsible
of the memory allocation and freeing for a multidimensional array.

Function `char** allocate_memory(int* xdim, int ydim)` creates a multidimensional
array variable that will contain *char* type elements and allocates memory for it.
The program will expect that memory is allocated first for pointers according to 
parameter *ydim*. After that, for each pointer, memory should be allocated according to 
elements in parameter *xdim*. This means that the first pointer should have enough
memory allocated to contain a string of length *xdim[0]* and so on. And since we 
are dealing with strings, you should take into consideration the terminating nil. 
Finally, return the created array.

Function `void free_array(char** w, int ydim)` will free all the memory allocated for
the multidimensional array *w*7
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** allocate_memory(int* xdim, int ydim){
	char** arr;
    arr = malloc(ydim * sizeof(char *));
	for (int j = 0; j < ydim; j++) {
        arr[j] = malloc((xdim[j] + 1)* sizeof(char));
    }
	return arr;
}

void free_array(char** w, int ydim){
    for (int j = 0; j < ydim; j++) {
        free(w[j]);
    }
	free(w);
}

void print_array(char** words, int num) {
	for (int j = 0; j < num; j++) {
		printf("%s\n", words[j]);
	}
}

void copy_to_array(char** dest, char** src, int num) {
	for (int j = 0; j < num; j++) {
		strcpy(dest[j], src[j]);
	}
}

// define the missing functions here

int main(void)
{

	char *static_words_1[] = {"dynamically", "allocated", "multidimensional", "arrays"};
	char *static_words_2[] = {"are", "FUN", "!"};

	int ydim_1 = 4;
	int xdim_1[] = {strlen(static_words_1[0]), strlen(static_words_1[1]), strlen(static_words_1[2]), strlen(static_words_1[3])};

	int ydim_2 = 3;
	int xdim_2[] = {strlen(static_words_2[0]), strlen(static_words_2[1]), strlen(static_words_2[2])};

	char** words = allocate_memory(xdim_1, ydim_1);

	copy_to_array(words, static_words_1, ydim_1);
	print_array(words, ydim_1);
	free_array(words, ydim_1);

	words = allocate_memory(xdim_2, ydim_2);

	copy_to_array(words, static_words_2, ydim_2);
	print_array(words, ydim_2);
	free_array(words, ydim_2);

	return 0;
}