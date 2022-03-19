// bitset.c
// Riesenie IJC-DU1, priklad a), 22.03.2022
// Autor: Andrej Smatana, FIT
// Prelozene: gcc 9.4.0

#include "bitset.h"

#ifdef USE_INLINE

extern inline unsigned long bitset_size(bitset_t jmeno_pole);
extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, const unsigned long index);
extern inline void bitset_setbit(bitset_t jmeno_pole, const unsigned long index, const unsigned long vyraz);
extern inline void bitset_free(bitset_t jmeno_pole);

#endif // USE_INLINE
