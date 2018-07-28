#ifndef NUMBER_H_
#define NUMBER_H_

#include <string>

#include "InfInt.h"

const int kTwo = 2;
const int kZero = 0;

class Number : public InfInt {
 public:
  Number(): InfInt() {}
  Number(const int number): InfInt(number) {}
  Number(const char* number): InfInt(number) {}
  Number(const std::string& number): InfInt(number) {}
  Number(const InfInt& number): InfInt(number) {}

  bool IsPrime();
  void NextPrime();
  bool IsRelativelyPrime(const Number &num);
};

bool Number::IsPrime() {
  Number it(kTwo), tmp, sqrt = intSqrt();
  bool result = true;
  sqrt++;
  for (; it <= sqrt; it++) {
    tmp = *this % it;
    if (tmp == kZero) {
      result = false;
      break;
    }
  }

  return result;
}

void Number::NextPrime() {
  for (; !this->IsPrime();this->operator++());
}

bool Number::IsRelativelyPrime(const Number &num) {
  Number greater_num = *this < num ? *this: num;
  Number limit_num = greater_num / kTwo;
  Number it(kTwo), modulo_result_this, modulo_result_num;
  bool result = true;

  for (;it <= limit_num; it++) {
    modulo_result_this = *this % it;
    modulo_result_num = num % it;

    if (modulo_result_num == 0 && modulo_result_this == 0) {
      result = false;
      break;
    }
  }

  return result;
}

#endif //  NUMBER_H_
