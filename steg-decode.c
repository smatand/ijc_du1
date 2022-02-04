#include <stdio.h>
#include <stdlib.h>

#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		error_exit("Program musi prijat jenom jeden argument s nazvem souboru ke cteni!");	
	}
	// get ppm data
	struct ppm *image = ppm_read(argv[1]); 	
	unsigned size = image->xsize * image->ysize * 3;

	// get prime number indexes of bytes from which the LSB bit will be read to assembly a char
	bitset_alloc(primes, size) 
	Eratosthenes(primes);
	char toPrint = '\0'; // in case of NULL the program will end with SUCCESS
	int count = 0;

	for (bitset_index_t i = 23; i<size; i += 2) {
		// when the bit on index i is 0, it's a prime number
		// in that case save the LSB of saved data to toPrint
		if (!bitset_getbit(primes, i)) {
//			printf("%c\n", image->data[i]);
			toPrint |= ((unsigned char)image->data[i] & 0x01) << count;
			count++;
		}
		if (count == 8) {
			printf("%c", toPrint);
			count = 0;
			if (toPrint == '\0') {
				break;
			}
			toPrint = '\0';
		}
	}

	ppm_free(image);
	bitset_free(primes);
	return 0;
}
