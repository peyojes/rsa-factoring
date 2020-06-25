#ifndef POLLARD_WITH_WISNIEWSKI_RSA_FACTORING_H
#define POLLARD_WITH_WISNIEWSKI_RSA_FACTORING_H
#include "factoring_method.h"

#include <vector>

class PollardWithWisniewskiRsaFactoring : public FactoringMethod {
 public:
  void Factoring();
  Number CalculateFactor();
};

inline void PollardWithWisniewskiRsaFactoring::Factoring() {
  Number factor(CalculateFactor());
  p_ = factor;
  q_ = GetModulus() / factor;
  CalculateEulerFunction();
//  FindPrivateKey();
}

using std::vector;
inline Number PollardWithWisniewskiRsaFactoring::CalculateFactor() {
  vector<Number> first_val_fun{2,2}, second_val_fun{2,2}, absolut{0,0}, factor{1,1};
  Number two(2), one(1), count(1), size(2), six(6);

  while (factor[0] == one && factor[1] == one) {
    for (; (count < size) && (factor[0] <= one); count++) {
      first_val_fun[0] =
          (six * first_val_fun[0] - 1) * (six * first_val_fun[0] - 1) %GetModulus();

      first_val_fun[1] =
          (six * first_val_fun[1] + 1) * (six * first_val_fun[1] + 1) %GetModulus();

      absolut[0] = first_val_fun[0].AbsolutSubtraction(second_val_fun[0]);
      absolut[1] = first_val_fun[1].AbsolutSubtraction(second_val_fun[1]);
      factor[0] = absolut[0].Gcd(GetModulus());
      factor[1] = absolut[1].Gcd(GetModulus());
    }
    size = two * size;
    second_val_fun = first_val_fun;
  }

  Number result;
  if (factor[0] != one) {
    result = factor[0];
  } else {
    result = factor[1];
  }

  return result;
}

#endif  // POLLARD_WITH_WISNIEWSKI_RSA_FACTORING_H
