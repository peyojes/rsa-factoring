#ifndef WISNIEWSKI_RSA_FACTORING_H
#define WISNIEWSKI_RSA_FACTORING_H
#include "factoring_method.h"
#include "rsa_data.h"

#include <vector>
#include <iostream>

class WisniewskiRsaFactoring : public FactoringMethod {
 public:
  void Factoring();
 private:
  void CalculatePQAndPrivateKey(const Number& x, const int number_of_equation);
  bool IsFound(const Number* mod_results, int *number_of_equation);
};

inline void WisniewskiRsaFactoring::Factoring() {
  Number  first_member[4], second_member[4], modulo_result[4], x(1), six(6);
  bool is_find = false;
  int number_of_equation = -1;
  while (!is_find) {
    x++;

    first_member[0] = six * ((x * six) + 1);
    first_member[1] = six * ((x * six) - 1);

    second_member[0] = GetModulus() - (six * x) - 1;
    second_member[1] = GetModulus() + (six * x) + 1;
    second_member[2] = GetModulus() - (six * x) + 1;
    second_member[3] = GetModulus() + (six * x) - 1;

    modulo_result[0] = second_member[0] % first_member[0];
    modulo_result[1] = second_member[1] % first_member[0];
    modulo_result[2] = second_member[2] % first_member[1];
    modulo_result[3] = second_member[3] % first_member[1];

    is_find = IsFound(modulo_result, &number_of_equation);
  }
  CalculatePQAndPrivateKey(x, number_of_equation);
}

inline void WisniewskiRsaFactoring::CalculatePQAndPrivateKey(
    const Number &x, const int number_of_equation) {

  if (number_of_equation <= 1 && number_of_equation >= 0) {
    p_ = x * 6 + 1;
  } else if (number_of_equation >= 2 && number_of_equation <=3) {
    p_ = x * 6 - 1;
  }

  q_ = GetModulus() / p_;
  CalculateEulerFunction();
  FindPrivateKey();
}

inline bool WisniewskiRsaFactoring::IsFound(const Number *mod_results,
                                            int *number_of_equation) {
  bool result = false;
  for (int it = 0; it < 4; it++) {
    if (mod_results[it] == Number(0)) {
      result = true;
      *number_of_equation = it;
    }
  }
  return result;
}

#endif  // WISNIEWSKI_RSA_FACTORING_H
