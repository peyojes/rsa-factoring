/*
 * g++ factoring.cc -o factoring -lpthread
 */


#ifndef SIMPLE_RSA_FACTORING_H
#define SIMPLE_RSA_FACTORING_H

#include "factoring_method.h"

class SimpleRsaFactoringStartingFromBeginning
    : public FactoringMethod {
 public:
  void Factoring();

 protected:
  void CalculatePQAndPrivateKey(const Number& iterator);
  void CalculateIfItIsPrime(const Number& iterator, Number& rest_with_division);
};


class SimpleRsaFactoringStartingFromMiddle
    : public SimpleRsaFactoringStartingFromBeginning {
 public:
  void Factoring();
};


void SimpleRsaFactoringStartingFromBeginning::Factoring() {
  Number it(2), rest_with_division, sqrt = (GetModulus().intSqrt())++;
  for (; it <= sqrt; it++) {
    CalculateIfItIsPrime(it, rest_with_division);
  }
}

void SimpleRsaFactoringStartingFromBeginning::CalculateIfItIsPrime(
  const Number &iterator,
  Number &rest_with_division) {
  rest_with_division = GetModulus() % iterator;
  if (rest_with_division == 0) {
    CalculatePQAndPrivateKey(iterator);
  }
}

void SimpleRsaFactoringStartingFromBeginning::CalculatePQAndPrivateKey(
    const Number &iterator) {
  p_ = iterator;
  q_ = GetModulus() / iterator;
  CalculateEulerFunction();
//  FindPrivateKey();
}

void SimpleRsaFactoringStartingFromMiddle::Factoring() {
  Number it(GetModulus().intSqrt()++), rest_with_division;
  for (; it >= 2; it--) {
    CalculateIfItIsPrime(it, rest_with_division);
  }
}
#endif // SIMPLE_RSA_FACTORING_H

