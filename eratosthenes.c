// eratosthenes.c
// Riesenie IJC-DU1, priklad a), 22.03.2022
// Autor: Andrej Smatana, FIT
// Prelozene: gcc 9.4.0

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t pole) {
	// assigning 1 on index 0 and 1 as it is nonprime number
	bitset_setbit(pole, 0, 1);
	bitset_setbit(pole, 1, 1);
		
	for (bitset_index_t i=2; i < sqrt(bitset_size(pole)); i++) {
		// set all multiplies of i to 1, as those are surely nonprime numbers
		if (!bitset_getbit(pole, i)) {
			for (bitset_index_t n=i*i; n < bitset_size(pole); n += i) {
				bitset_setbit(pole, n, 1);
			}
		}
	}
}
