#include <stdio.h>
#include <time.h>
#include "eratosthenes.h"
#include "bitset.h"
#include "error.h"

#define MAX 300000000
#define TEMP 10

int main(void) {
	bitset_create(bit_arr, MAX);
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
	return 0;
}
