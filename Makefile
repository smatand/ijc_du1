# primes-i should have -O0 arg
FLAGS = -O2 -pedantic -std=c11 -g3 -Wall -Wextra
CC = gcc
EXECUTABLES = primes primes-i steg-decode
FILES = *

all: $(EXECUTABLES)

error.o: error.c
	$(CC) $(FLAGS) -c error.c -o error.o

primes: primes.o error.o eratosthenes.o bitset.o
	$(CC) $(FLAGS) primes.o error.o eratosthenes.o bitset.o -o primes -lm
primes-i: primes-i.o error.o eratosthenes-i.o bitset-i.o
	$(CC) $(FLAGS) primes-i.o error.o eratosthenes-i.o bitset-i.o -o primes-i -lm
steg-decode: steg-decode.o bitset.o error.o ppm.o
	$(CC) $(FLAGS) steg-decode.o bitset.o error.o ppm.o eratosthenes.o -o steg-decode -lm

primes.o: primes.c
	$(CC) $(FLAGS) -c primes.c -o primes.o
eratosthenes.o: eratosthenes.c
	$(CC) $(FLAGS) -c eratosthenes.c -o eratosthenes.o
bitset.o: bitset.c
	$(CC) $(FLAGS) -c bitset.c -o bitset.o

primes-i.o: primes.c
	$(CC) $(FLAGS) -DUSE_INLINE -c primes.c -o primes-i.o
eratosthenes-i.o: eratosthenes.c
	$(CC) $(FLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o
bitset-i.o: bitset.c
	$(CC) $(FLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o
 
ppm.o: ppm.c
	$(CC) $(FLAGS) -c ppm.c -o ppm.o
steg-decode.o: steg-decode.c
	$(CC) $(FLAGS) -c steg-decode.c -o steg-decode.o

run:
	make all
merlin:
	scp -r $(FILES) xsmata03@merlin.fit.vutbr.cz:~/ijc_uloha1
clean: 
	rm -f *.o $(EXECUTABLES)
