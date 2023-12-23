#include "bits.h"
#include <stdio.h>
#include <stdlib.h>

/* NOTE:
 * -----------
 * The parameter binary data (const unsigned char*) in all the functions 
 * below is likely to hold more than 8 bits. You should take this into 
 * account when implementing your functions.
 */

/* DESCRIPTION:
 * ------------
 * The function sets a bit with index i as active (1) in the parameter
 * binary data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * unsigned char* data: an array of binary data.
 * int i: the index of the bit which to set as active (1).
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */
void op_bit_set(unsigned char* data, int i)
{
    int indexModified = i / 8;
    int bitPosition = i % 8;
    data[indexModified] |= (1 << (7 - bitPosition));
}

/* DESCRIPTION:
 * ------------
 * The function sets a bit with index i as inactive (0) in the parameter
 * binary data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * unsigned char* data: an array of binary data.
 * int i: the index of the bit which to set as active (1).
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */

void op_bit_unset(unsigned char* data, int i) {
    int indexModified = i / 8;
    int bitPosition = i % 8;
    int bitUnset = ~(1 << (7 - bitPosition));
    data[indexModified] &= bitUnset;
}

/* DESCRIPTION:
 * ------------
 * The functions returns 1 or 0 depending on whether the bit with index i in
 * the binary data is set or not.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * const unsigned char* data: an array of binary data.
 * int i: the index of the bit which value to return.
 *
 * RETURNS:
 * ------------
 * 0: if the bit was not set.
 * 1: if the bit was set.
 */

int op_bit_get(const unsigned char* data, int i) {
    int indexModified = i / 8;
    int bitPosition = i % 8;
    int digitExtracted = (data[indexModified] >> (8 - bitPosition - 1)) & 1;
    if ((digitExtracted ^ 0) == 0) {
      return 0;
    } else return 1;
}

/* DESCRIPTION:
 * ------------
 * The function prints the binary representation of the parameter unsigned char
 * to the standard output as 1s and 0s. Note that one unsigned char is 8 bits.
 * There is no newline at the end of the print.
 *
 * For example:
 *
 * unsigned char b = 0xF8;
 * print_byte(b); 
 *
 * Would print out:
 *
 * 11111000
 *
 * PARAMETERS:
 * ------------
 * unsigned char b: the binary sequence.
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */

void op_print_byte(unsigned char b)
{
    for (int i = 7; i >= 0; i--){
        unsigned int bit = (b >> i) & 1;  
        printf("%d", bit);
    }
}

/* DESCRIPTION:
 * ------------
 * The function extracts a sequence of bits from the binary data. The length of 
 * the sequence is defined in by the parameter how_many and the sequence starts
 * from index i (inclusive).
 *
 * If the parameter how_many is less than 8, the byte will be padded with zeroes
 * on the left side. For example if you extract 2 bits (11), the return value
 * is 00000011, which is equal to 3.
 *
 * The maximum length of extracted sequence for this function is 8, you do not
 * need to handle any invalid parameters.
 *
 * NOTE: The const unsigned char* data is likely to hold more than one byte of
 *       information. The extracted sequence also can continue over byte
 *       boundaries i.e. the extracted bit data can exist within two different
 *       bytes.
 *
 * PARAMETERS:
 * ------------
 * const unsigned char* data: an array of binary data, where the sequence is 
 * extracted from.
 *
 * int i: the starting index of the extracted sequence.
 * int how_many: the length of the extracted sequence.
 *
 * RETURNS:
 * ------------
 * The extracted sequence stored in a single unsigned char.
 *
 */


unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many) {
    if (how_many == 0) return 0;
    unsigned char extract = 0;
    int count = how_many - 1;
    for (int j = i; j <= i + how_many - 1; j++){
        int bitGet = op_bit_get(data, j);
        extract |= (bitGet << count);
        count--; 
    }
    return extract;
}

