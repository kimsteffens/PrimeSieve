#include <stdio.h>
#include "sieve.h"
#include <string.h> 
#include <unistd.h>

/**
 * The sieve function finds all prime numbers up to a certain limit, as well as counts them. 
 * It works by setting an array of the size of all numbers up until limit to be 1 (meaning they are prime), and then 
 * using the prime sieve algorithm to find which numbers are not prime and set them to 0 (meaning not prime).
 *
 * @author Kim Steffens
 * @version April 9, 2017
**/
 uint64_t * sieve(uint64_t limit, int * status, size_t * primeCount) {

   // pointer to an array to return
   uint64_t * primeArray = malloc(sizeof(uint64_t) * (limit + 1));
   if (primeArray == NULL)
     return NULL;

   // first fill out all of the numbers to be checked for primeness
   // set initially as one (meaning prime)
   unsigned long long i = 2;
   for (i = 2; i <= limit; i++) {
     primeArray[i] = 1;
   }

   // zero and one cannot be prime
   primeArray[0] = 0;
   primeArray[1] = 0;

   // count the numbers that are not prime
   int reduce = 2;

   // next check if the numbers are prime
   unsigned long long j = i = 2;
   for (i = 2; i <= limit; i++) {

     // this number is prime if it is 1, meaning its multiples are not prime
     if (primeArray[i] == 1) {
       for (j = i; i * j <= limit; j++) {

         // make sure that it was not already marked non-prime
         if (primeArray[i * j] != 0) {
           primeArray[i * j] = 0;

           // if another non-prime is found, we should reduce the primeCount more
           reduce++;
         }
       }
     }
   }

   // calculate primeCount
   * primeCount = (limit + 1) - reduce;

   return primeArray;

 }

