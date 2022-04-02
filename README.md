### IJC - Project 1
*Part 1 - Finds primes using Sieve of Eratosthenes  
Part 2 - Decrypts a secret message hidden in .ppm image format*

Compile `make`.  
  
Find last 10 prime numbers in range of `0` - `300 000 000` by typing `./primes` 
*(before doing so you will need to change the stack limit by typing `ulimit -s 40000` on Linux)*.  
If you want to change the range, change the value of constant `MAX` in file `primes.c` and recompile again.  
  
`./steg-decode du1-obrazek.ppm` decrypts a secret message hidden at 1st bits of prime numbers starting from 29.  
