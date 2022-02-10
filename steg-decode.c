#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"

int main(int argc, char* argv[]) {
	// program must have 1 argument with name of file to open
	if (argc != 2) {
		error_exit("Program musi prijat jenom jeden argument s nazvem souboru ke cteni!");	
	}
	// get ppm data
	struct ppm *image= ppm_read(argv[1]); 	
	// set the size of ppm, so the bitset array will be created
	unsigned size = image->xsize * image->ysize * 3;

	bitset_alloc(primes, size) 
	Eratosthenes(primes); // get prime indexes of bitset

	char * toPrint = malloc(1); // sizeof(char) == 1
	int count = 0; // used to count 8 bits which create a char value
	int index = 0; // saving newly created chars at toPrint[index]
	int isNull = 0; // we may print the string only if the NULL char is defined

	for (bitset_index_t i = 23; i<size; i += 2) {
		// if bitset[i] == 0, then it's a prime number
		// in that case save the LSB of saved data to toPrint
		if (!bitset_getbit(primes, i)) {
			toPrint[index] |= ((unsigned char)image	->data[i] & 0x01) << count;
			count++;
		}
		if (count == 8) {
//			printf("%c", toPrint);
			count = 0;
//			todo: check the error of valgrind here			
			if (toPrint[index] == '\0') {
				isNull = 1;
				break;
			}
			toPrint = realloc(toPrint, ++index+1);
			toPrint[index] = '\0';
		}
	}
	// in case of missing '\0' char, exit(1) must be called
	if (!isNull) {
		free(toPrint);
		ppm_free(image);
		bitset_free(primes);
		error_exit("Nenalezena tajna zprava, resp. chybi '\0' znak.\n");
	}

	// in case of found '\0' char, the program ends with success
	printf("%s", toPrint);

	free(toPrint);
	ppm_free(image);
	bitset_free(primes);

	return 0;
}
