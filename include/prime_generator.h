#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H
#include "number.h"

#include <cstdlib>
#include <ctime>
#include <random>

class PrimeGenerator{
 public:
  Number GeneratePrime(const unsigned int number_of_digits);
};


inline Number PrimeGenerator::GeneratePrime(const unsigned int number_of_digits) {
  srand((unsigned)time(0));
  Number result((std::rand() % 9) + 1);

  for (unsigned int it(1); it < number_of_digits; it++){
    result *= 10;
    result += (std::rand() % 9) +1;
  }

  result.NextPrime();
  return result;
}

#endif
