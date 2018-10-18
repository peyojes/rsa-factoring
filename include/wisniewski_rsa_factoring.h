#ifndef WISNIEWSKI_RSA_FACTORING_H
#define WISNIEWSKI_RSA_FACTORING_H
#include "factoring_method_interface.h"
#include "rsa_data.h"

#include <vector>

class WisniewskiRsaFactoring : public RsaData, FactoringMethodInterface {
 public:
  void Factoring();
 private:
  void CalculatePQAndPrivateKey(const Number& x);
  bool IsFound(const Number* mod_results);
};

inline void WisniewskiRsaFactoring::Factoring() {
  Number  first_member[4], second_member[4], modulo_result[4], x(1), six(6);
  bool is_find = false;
  while (!is_find) {
    x++;

    first_member[0] = six * ((x * six) + 1);
    first_member[1] = six * ((x * six) - 1);

    second_member[0] = GetModulus() - (six * x) - 1;
    second_member[1] = GetModulus() + (six * x) + 1;
    second_member[2] = GetModulus() - (six * x) + 1;
    second_member[3] = GetModulus() + (six * x) - 1;

    modulo_result[0] = first_member[0] % second_member[0];
    modulo_result[1] = first_member[0] % second_member[1];
    modulo_result[2] = first_member[1] % second_member[2];
    modulo_result[3] = first_member[1] % second_member[3];

    is_find = IsFound(modulo_result);
  }
  CalculatePQAndPrivateKey(x);
}

inline void WisniewskiRsaFactoring::CalculatePQAndPrivateKey(const Number &x) {
  p_ = x;
  q_ = GetModulus() / p_;
  CalculateEulerFunction();
  FindPrivateKey();
}

inline bool WisniewskiRsaFactoring::IsFound(const Number *mod_results) {
  bool result = false;

  for (int it = 0; it < 4; it++) {
    if (mod_results[it] == Number(0)) {
      result = true;
    }
  }
  return result;
}

#endif  // WISNIEWSKI_RSA_FACTORING_H
