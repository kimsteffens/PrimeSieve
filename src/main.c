#include <stdio.h>
#include <string.h> 
#include "sieve.h"
#include <unistd.h>

/**
 * Uses the sieve function to find prime numbers up to a certain limit. The user can choose to print out all primes using -p as a command line argument.
 * Otherwise, simply the number of primes up until the command line argument defined limit is reached. 

 * @author Kim Steffens
 * @version April 9, 2017
**/
  int main(int argc, char * argv[]) {

  // if too many arguments are passed
  if (argc > 3) {
    printf("Too many arguments. SIEVE_INVALID_ARGUMENT \n");
    return SIEVE_INVALID_ARGUMENT;

    // if 2 arguments are passed
  } else if (argc == 3) {

    // first argument must be -p
    if (strcmp(argv[1], "-p") != 0) {
      printf("Invalid argument. SIEVE_INVALID_ARGUMENT \n");
      return SIEVE_INVALID_ARGUMENT;
    }
    // things to pass through function
    int status;
    size_t primeCount = 0;
    uint64_t limit = atoi(argv[2]);

    // if invalid limit
    if (limit < 2) {
      printf("Invalid argument. SIEVE_INVALID_ARGUMENT \n");
      return SIEVE_INVALID_ARGUMENT;
    }

    uint64_t * primeArray;

    // get the array
    primeArray = sieve(limit, & status, & primeCount);

    // check if memory ran out
    if (primeArray == NULL) {
      printf("Memory failure. SIEVE_OUT_OF_MEMORY");
      return SIEVE_OUT_OF_MEMORY;
    }

    // print out after two seconds
    printf("Now printing primes from 2 to %d..... \n", limit);
    sleep(2);
    unsigned long long i = 0;
    for (i = 0; i <= limit; i++)
      if (primeArray[i])
        printf("%d \n", i);

      // print number of primes
    printf("The prime count: %d \n", primeCount);

    free(primeArray);

    return SIEVE_OK;

    // if only one argument passed
  } else if (argc == 2) {

    // things to pass through function
    int status;
    size_t primeCount = 0;
    uint64_t limit = atoi(argv[1]);

    // if invalid limit
    if (limit < 2) {
      printf("Invalid argument. SIEVE_INVALID_ARGUMENT \n");
      return SIEVE_INVALID_ARGUMENT;
    }

    // get array
    uint64_t * primeArray;
    primeArray = sieve(limit, & status, & primeCount);

    // check if memory ran out
    if (primeArray == NULL) {
      printf("Memory failure. SIEVE_OUT_OF_MEMORY");
      return SIEVE_OUT_OF_MEMORY;
    }

    // print number of primes
    printf("The prime count: %d \n", primeCount);

    free(primeArray);
    return SIEVE_OK;

  } else {
    printf("Invalid argument. SIEVE_INVALID_ARGUMENT \n");
    return SIEVE_INVALID_ARGUMENT;
  }

}
