#ifndef SIMPLE_RSA_FACTORING_H
#define SIMPLE_RSA_FACTORING_H

#include "factoring_method_interface.h"

class SimpleRsaFactoringStartingFromBeginning
    : public RsaData, FactoringMethodInterface {
 public:
  SimpleRsaFactoringStartingFromBeginning(): RsaData() {}
  void Factoring();

private:
  void CalculatePQAndPrivateKey(const Number& iterator);
  void CalculateIfItIsPrime(const Number& iterator, Number& rest_with_division);
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
  if (iterator.IsPrime()) {
    rest_with_division = GetModulus() % iterator;
    if (rest_with_division == 0) {
      CalculatePQAndPrivateKey(iterator);
    }
  }
}

void SimpleRsaFactoringStartingFromBeginning::CalculatePQAndPrivateKey(
    const Number &iterator) {
  p_ = iterator;
  q_ = GetModulus() / iterator;
  CalculateEulerFunction();
  FindPrivateKey();
}

#endif // SIMPLE_RSA_FACTORING_H
