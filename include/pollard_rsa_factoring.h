#ifndef POLLARD_RSA_FACTORING_H
#define POLLARD_RSA_FACTORING_H
#include "factoring_method.h"
#include "rsa_data.h"

class PollardRsaFactoring : public FactoringMethod {
 public:
  void Factoring();
 private:
  void CalculateFactor(Number &factor);
};

inline void PollardRsaFactoring::Factoring() {
  Number factor(1);
  CalculateFactor(factor);
  p_ = factor;
  q_ = GetModulus() / factor;
  CalculateEulerFunction();
  FindPrivateKey();
}

inline void PollardRsaFactoring::CalculateFactor(Number &factor) {
  Number first_val_fun(2), second_val_fun(2), two(2),
         one(1), count(1), size(2), absolut(0);

  while (factor == one) {
    for (; (count < size) && (factor <= one); count++) {
      first_val_fun = (first_val_fun * first_val_fun + one) %GetModulus();
      absolut = first_val_fun.AbsolutSubtraction(second_val_fun);
      factor = absolut.Gcd(GetModulus());
    }
    size = two * size;
    second_val_fun = first_val_fun;
  }
}

#endif  // POLLARD_RSA_FACTORING_H
