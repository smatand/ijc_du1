#ifndef BITSET_H
#define BITSET_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "error.h"

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

#define ULONG               ((sizeof(unsigned long)) * (CHAR_BIT))
#define MAX_SIZE(velikost)  ((velikost / ULONG) + 1 + ((velikost % ULONG != 0) ? 1 : 0))

#define GETBIT(jmeno_pole, index) (jmeno_pole[(index/ULONG)+1] >> ((index) % ULONG) & 1UL)
#define SETBIT(jmeno_pole, index, vyraz) (vyraz) ? (jmeno_pole[(index/ULONG)+1] |= (1UL << (index % ULONG))) : \
												   (jmeno_pole[(index/ULONG)+1] &= (1UL << (index % ULONG)))

// todo: edit static_assert
// macro for creating array jmeno_pole with size of velikost
#define bitset_create(jmeno_pole, velikost)                          \
	static_assert(((unsigned long)velikost >= 0),                     \
		"Velikost pro alokaci bitset_t pole musi byt kladny cislo!");\
	unsigned long jmeno_pole[MAX_SIZE(velikost)] = {velikost};	 	 

// macro for dynamically alloc bitset jmeno_pole with size of velikost
#define bitset_alloc(jmeno_pole, velikost) assert(!(velikost <= 0)); bitset_t jmeno_pole = calloc(MAX_SIZE(velikost), sizeof(unsigned long));\
    if (jmeno_pole == NULL) error_exit("bitset_alloc: Chyba alokace pameti");\
	jmeno_pole[0] = velikost;

/////////////////////////////////// USE_INLINE ////////////////////////////////////////////////////////////////////////
#ifndef USE_INLINE

// macro for size of jmeno_pole array
#define bitset_size(jmeno_pole) jmeno_pole[0]

// macro to set value of jmeno_pole[index] to vyraz
#define bitset_setbit(jmeno_pole, index, vyraz)                                                         \
	((index) >= bitset_size(jmeno_pole) ?    (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",  \
												(unsigned long)index, bitset_size(jmeno_pole)), 0)   : \
										    (SETBIT(jmeno_pole, index, vyraz)))

// macro to get value of jmeno_pole[index]
#define bitset_getbit(jmeno_pole, index)                                                                \
	((index) >= bitset_size(jmeno_pole) ?   (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", \
												(unsigned long)index, (unsigned long)bitset_size(jmeno_pole)), 0)   : \
											(GETBIT(jmeno_pole, index)))

// macro for freeing malloc
#define bitset_free(jmeno_pole) free(jmeno_pole)

#else

inline unsigned long bitset_size(bitset_t jmeno_pole) {
	return jmeno_pole[0];
}

inline void bitset_setbit(bitset_t jmeno_pole, const unsigned long index, const unsigned long vyraz) {
	if (index > bitset_size(jmeno_pole)) {
		error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",
				   (unsigned long)index, bitset_size(jmeno_pole));
	}
	SETBIT(jmeno_pole, index, vyraz);
}

inline unsigned long bitset_getbit(bitset_t jmeno_pole, const unsigned long index) {
	if (index > bitset_size(jmeno_pole)) {
		error_exit("bitset_getbit: index %lu mimo rozsah 0..%lu",
				(unsigned long)index, bitset_size(jmeno_pole));
	}
	return GETBIT(jmeno_pole, index);
}

inline void bitset_free(bitset_t jmeno_pole) {
	free(jmeno_pole);
}
#endif // USE_INLINE
/////////////////////////////////// USE_INLINE ////////////////////////////////////////////////////////////////////////
#endif // BITSET_H
