# PrimeSieve
A command-line program in C that finds the prime numbers up to a certain limit by using the prime sieve algorithm.

## Usage

Be sure to link the files when compiling:

gcc -c sieve.c
gcc -c main.c
gcc sieve.o main.o -o main

To use simply run:

./main *-p limit*

  Make "-p" is an optional parameter that allows you to print all prime numbers found. "limit" is the number up to which the number of primes will be found.
  
  
  For example, running "./main -p 20" would yield:
  
             Now printing primes from 2 to 20.....
             
              2
              
              3
              
              5
              
              7
              
              11
              
              13
              
              17
              
              19
              
              The prime count: 8

