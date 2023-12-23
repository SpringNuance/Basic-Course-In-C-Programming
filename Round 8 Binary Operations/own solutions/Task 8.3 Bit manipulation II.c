/*
Implement below function **mergeBits** which takes two 4 bit number as input values 
and returns a 8 bit value. This 8 bit value is formed from the two input values **a**
and **b**. The value **a** forms the 4 higher order bits of the return value whereas
**b** forms 4 lower order bits of the return value. For example, when a function 
is called as follows: `mergeBits (0x6, 0xD)`, then result will be eight-bit number, 
which is the hexadecimal representation `6D`.
*/

#include <stdio.h>

// define mergeBits function here
unsigned char mergeBits(unsigned char a, unsigned char b) {
    unsigned char shifted = a << 4;
    return (shifted + b);
}

int main(void) {

    printf("%02x\n", mergeBits(0x5, 0xE));
    printf("%02x\n", mergeBits(0xA, 0xC));
    printf("%02x\n", mergeBits(0xD, 0x2));
    return 0;
}
