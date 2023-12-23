/*
Implement below function **sixBits** which returns only least significant six bits 
of the input value **v**. Rest of the two highest significant bits must be reset.
(i.e) If the input value **v** is **11110000**, then **sixBits** function must return 
**110000**. One way to accomplish this is to use a bit mask.
*/

#include <stdio.h>

// define sixBits function here
unsigned char sixBits(unsigned char v) {
    unsigned char filter = 0x3F;
    return (v & filter);
}

int main(void)
{
    printf("%02x\n", sixBits(0xDF));
    printf("%02x\n", sixBits(0x8D));
    printf("%02x\n", sixBits(0x28));
    return 0;
}
