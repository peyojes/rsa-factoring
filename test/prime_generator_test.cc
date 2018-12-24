/**
  * @name prime_generator_test.cc
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#include <gtest/gtest.h>
#include <iostream>

#include "../include/prime_generator.h"

TEST(PrimeGenerator, generatePrimeWithOneDigits) {
  PrimeGenerator prime_generator;
  Number number(prime_generator.GeneratePrime(1));
  EXPECT_TRUE(number.IsPrime());
}

TEST(PrimeGenerator, generatePrimeWithThreeDigits) {
  PrimeGenerator prime_generator;
  Number number(prime_generator.GeneratePrime(4));
  EXPECT_TRUE(number.IsPrime());
  std::cout << "Prime: " << number << "\n";
}
