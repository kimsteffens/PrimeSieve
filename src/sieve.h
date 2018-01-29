#include<stdint.h>

#define SIEVE_OK 0
#define SIEVE_INVALID_ARGUMENT 1
#define SIEVE_OUT_OF_MEMORY 2
uint64_t* sieve(uint64_t limit, int* status, size_t* primeCount);

