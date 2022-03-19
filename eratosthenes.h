// eratosthenes.h
// Riesenie IJC-DU1, priklad a), 22.03.2022
// Autor: Andrej Smatana, FIT
// Prelozene: gcc 9.4.0

#include "bitset.h"

#ifndef ERATOSTHENES_H
#define ERATOSTHENES_H

/**
 * @brief	Find all prime numbers
 * @details searches for prime numbers using the algorithm Sieve of Eratosthenes
 *			bits stored in pole[index], where the index is prime number, are set to 0
 *
 * @param	pole to read data from
 */
void Eratosthenes(bitset_t pole);

#endif
