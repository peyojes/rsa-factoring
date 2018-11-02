#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H
#include "number.h"

#include <cstdlib>
#include <ctime>

class PrimeGenerator{
 public:
  Number GeneratePrime(const unsigned int number_of_digits);
};

#endif

inline Number PrimeGenerator::GeneratePrime(const unsigned int number_of_digits) {
  srand((unsigned)time(0));
  Number result(rand() % 10);

  for (unsigned int it(1); it < number_of_digits; it++){
    result *= 10;
    result += rand() % 10;
  }

  result.NextPrime();
  return result;
}
