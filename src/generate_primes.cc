#include "../include/prime_generator.h"
#include <iostream>
#include <cstdlib>

using std::cout;

int main(int argc, char *argv[]) {
  PrimeGenerator prime_generator;

  if (argc != 3) {
    cout << "Wrong input parameters!\n"
              "\tusage: a.out number_of_digits number_of_primes\n";
    return 0;
  }
  unsigned int number_of_digits(atoi(argv[1])), number_of_primes(atoi(argv[2]));

  for (unsigned int it(0); it < number_of_primes; it++) {
    cout << prime_generator.GeneratePrime(number_of_digits) << "\n";
  }
  return 0;
}
