#ifndef FERMAT_RSA_FACTORING_H
#define FERMAT_RSA_FACTORING_H
#include "rsa_data.h"
#include "factoring_method.h"

class FermatRsaFactoring : public FactoringMethod {
 public:
  void Factoring();
};

void FermatRsaFactoring::Factoring() {
  Number a(GetModulus().intSqrt());
  a++;
  Number b((a * a) - GetModulus());

  while (!b.IsSqrt()) {
    a = a + 1;
    b = (a * a) - GetModulus();
  }

  p_ = a - b.intSqrt();
  q_ = a + b.intSqrt();
  CalculateEulerFunction();
//  FindPrivateKey();
}
#endif  // FERMAT_RSA_FACTORING_H
