#include <stdio.h>
#include <time.h>
#include "eratosthenes.h"
#include "bitset.h"
#include "error.h"

#define MAX 200000000
#define TEMP 10

int main(void) {
//	clock_t start = clock();
	bitset_create(bit_arr, MAX)
//	bitset_alloc(bit_arr, MAX)
	Eratosthenes(bit_arr);

	// save last 10 primes to another array
	unsigned long count=TEMP;
	unsigned long primes[TEMP] = {0};

	for (bitset_index_t i=bitset_size(bit_arr)-1; i>0;  i--) {
		if (!bitset_getbit(bit_arr, i)) {
			if (!count) {
				break;
			}
			--count;
			primes[count] = i;
		}
	}
	for (count=0; count<TEMP; count++) {
		printf("%lu\n", primes[count]);
	}
//	bitset_free(bit_arr);
//	clock_t end = clock();
//	fprintf(stderr, "Time=%.3g\n", (double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
