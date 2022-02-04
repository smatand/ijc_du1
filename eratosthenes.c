#include <stdio.h>
#include <math.h>
#include <time.h>
#include "eratosthenes.h"

/**
 * find all prime numbers in bitset_t pole (array) by Sieve of Eratosthenes
 * print last 10 of them, each on new line in ascending order
 * result: in pole (array) prime indexes have value of 0
 *
 * @param pole to read data from
 */
void Eratosthenes(bitset_t pole) {
	// assigning 1 as it is nonprime num
//	clock_t a = clock();
	bitset_setbit(pole, 0, 1);
	bitset_setbit(pole, 1, 1);
//	clock_t b = clock();
//	fprintf(stderr, "bitset_setbit Time=%.3g\n", (double)(b-a)/CLOCKS_PER_SEC);
//	PRINT_(pole, 1)
//	printf("%lu\n", (unsigned long)sqrt(bitset_size(pole)));
		
	for (bitset_index_t i=2; i < sqrt(bitset_size(pole)); i++) {
	//	printf("pole[%lu/%ld +1] >> ((%ld %% %ld)) & 1UL = %ld\n", i, ULONG, i, ULONG, GETBIT(pole, i));
		// set all multiplies of i to 1, as those are surely nonprime numbers
//		clock_t start = clock();
		if (!bitset_getbit(pole, i)) {
			for (bitset_index_t n=i*i; n < bitset_size(pole); n += i) {
				bitset_setbit(pole, n, 1);
				//printf("setbit: pole[%lu/%ld +1] >> ((%ld %% %ld)) & 1UL = %ld\n", n, ULONG, n, ULONG, GETBIT(pole, n));
			}
//		clock_t end = clock();
//		fprintf(stderr, "Time=%.3g\n", (double)(end-start)/CLOCKS_PER_SEC);
		}
	}
}
