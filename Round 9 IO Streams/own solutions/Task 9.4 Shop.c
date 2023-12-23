#include "shop.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/* 
(a) function write_binary which outputs a binary format file from given Product array with parameter 
name shop. Another parameter for this function is filename, the name of the desired output file. 
If the function succeeded, it should return 0, otherwise it should return 1.
*/
int write_binary(const char* filename, const Product* shop) {
   FILE* filePtr = fopen(filename, "wb");
    if (filePtr == NULL ){
        return 1;
    }
    long unsigned int i = 0;
	while (shop[i].name[0]){
      i++;
	}
    
    if (fwrite(shop, sizeof(Product), i , filePtr) != i){
        return 1;
    }
	
    fclose(filePtr);
    return 0;
}

/*
(b) function read_binary, which reads a binary format file (written in section a) and outputs the read data 
into a Product-array. After reading the data the function should return a pointer to this array. 
The function must allocate the memory for this array and the reading format should be so that 
the first array element read from the binary file should be in the first index of the list. 
Also remember to mark the last element of the list as described before. 
If the function does not succeed, it should return a NULL pointer.
*/
Product* read_binary(const char* filename) {
   FILE* filePtr = fopen(filename, "rb");
    if (filePtr == NULL ){
        return NULL;
    }
    int i = 0;
    Product * shop = malloc(sizeof(Product) + 1);
    int check = fread(&shop[i], sizeof(Product), 1, filePtr);
    while (check == 1) {
        shop = realloc(shop, (i + 2) * sizeof(Product) + 1);
        check = fread(&shop[i + 1], sizeof(Product), 1, filePtr);
        i++;
    }    
    shop[i].name[0] = 0;
    fclose(filePtr);
    return shop;
}

/*
(c) function write_plaintext, which outputs a plaintext format (ie. human readable) from 
the given Product array shop. The file format should be following:
yoghurt 1.2 23
muesli 4.3 12
As seen the data items of the struct are separated with a space, and the array elements are separated 
by a newline. Because the data items are separated by a space, the product name should not have spaces in it. 
Into this plaintext product file the last element (with the name of null character) should not be printed at all. 
As in the a-case, if the function succeeded, it should return 0, otherwise it should return 1.
*/

int write_plaintext(const char* filename, const Product* shop) {
    FILE* filePtr = fopen(filename, "w");
    if (filePtr == NULL ){
        return 1;
    }
    
    int i = 0;
	while (shop[i].name[0]){
      int check = fprintf(filePtr, "%s %f %d\n", shop[i].name, shop[i].price, shop[i].in_stock);
      if (check < 0){
          return 1;
      }
      i++;
	}
	
    fclose(filePtr);
    return 0;
}

/*
(d) function read_plaintext which reads a plaintext file (written in section c) and outputs the read data 
into a Product-array. After reading the data the function should return a pointer to this array. 
The function must allocate the memory for this array and the reading format should be so that 
the first array element read from the binary file should be in the first index of the list. 
Also remember to mark the last element of the list as described in the very beginning of this task. 
If the function does not succeed, it should return a NULL pointer.
*/
Product* read_plaintext(const char* filename) {
  FILE* filePtr = fopen(filename, "r");
    if (filePtr == NULL ){
        return NULL;
    }
    
    Product * shop = malloc(sizeof(Product));
    int i = 0;
    int check = fscanf(filePtr, "%s %f %d\n", shop[i].name, &shop[i].price, &shop[i].in_stock);
    while (check > 0) {
        shop = realloc(shop, (i + 2) * sizeof(Product));
        i++;
        check = fscanf(filePtr, "%s %f %d\n", shop[i].name, &shop[i].price, &shop[i].in_stock);
    }    
    shop[i].name[0] = 0;
    fclose(filePtr);
    return shop;
}
