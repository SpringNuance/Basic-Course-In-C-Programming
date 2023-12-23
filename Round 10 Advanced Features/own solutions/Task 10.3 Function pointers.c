#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

int compareAlpha(const void* a, const void* b)
{
    const Product *shop_a = (const Product*)a;
    const Product *shop_b = (const Product*)b;
    int ret = strcmp( shop_a -> name, shop_b -> name);
    return ret;
}
/* Same as compareAlpha but compares the product *in_stock* numerically.
 * If there are two or more products with same *in_stock* -value, they are compared lexically.
+ int compareNum(const void a*, const void b*) function compares the in_stock fields of the 
Product parameters. Numerically larger should come first in the ordering. The function returns 
a negative number if b should be after a in the ordering and a positive number in the opposite case. 
If the two values are the same, the ordering is determined by compareAlpha.
 */

int compareNum(const void* a, const void* b)
{
	const Product* shop_a = (const Product*)a;
    const Product* shop_b = (const Product*)b;
    int stockA = shop_a -> in_stock;
	int stockB = shop_b -> in_stock;
    if (stockA < stockB) {
		return 1;
	} else if (stockA > stockB) {
		return -1;
	} else {
        int res = compareAlpha(a,b);
		return res;
	}
}
/* Finds a product from a sorted array of products
 * Returns: Whatever bsearch returned.
 * IMPORTANT: Remember that bsearch takes a pointer to a type as first parameter, and 
 * pointer to an array with same type elements as in first parameter.
 */
const Product* findProduct(const Product* p_array, const char* search_key, int (*cmp)(const void*, const void*))
{
    int i = 0;
	while(p_array[i].name[0] != 0){
		i++;
	}
	return bsearch(search_key, p_array, i, sizeof(Product), cmp);
}

