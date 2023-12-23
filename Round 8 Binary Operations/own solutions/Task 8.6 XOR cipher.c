#include <stdio.h>
#include <stdint.h>
#include "xorcipher.h"



/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 */
void confidentiality_xor(uint32_t key, void* data, int len)
{
	for (int i = 0; i <= len - 1; i++){
       ((uint32_t*) data)[i] ^= key;
	}
}

/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 * After encrypting one 32-bit block of original data, the key shifts one bit left
 */
void confidentiality_xor_shift(uint32_t key, void* data, int len)
{
	for (int i = 0; i <= len - 1; i++){
       ((uint32_t*) data)[i] ^= key;
	   uint32_t leftPart = key << 1;
	   uint32_t rightPart = key >> 31;
	   key = leftPart | rightPart;
	}

}

void print_uint32_hex(void* data, int len)
{
	for(int i = 0; i < len; i++) printf("0x%08x ", ((uint32_t*)data)[i]);
	printf("\n");
}

