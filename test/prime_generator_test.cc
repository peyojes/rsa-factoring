#include <gtest/gtest.h>
#include "../include/prime_generator.h"
#include <iostream>

TEST(PrimeGenerator, generatePrimeWithOneDigits) {
  PrimeGenerator prime_generator;
  Number number(prime_generator.GeneratePrime(1));
  EXPECT_TRUE(number.IsPrime());
}

TEST(PrimeGenerator, generatePrimeWithThreeDigits) {
  PrimeGenerator prime_generator;
  Number number(prime_generator.GeneratePrime(3));
  EXPECT_TRUE(number.IsPrime());
  std::cout << "Prime: " << number << "\n";
}
