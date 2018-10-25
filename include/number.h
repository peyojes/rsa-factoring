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

  bool IsPrime() const;
  bool IsPrimeStartMiddle() const;
  void NextPrime();
  bool IsRelativelyPrime(const Number &num);
  Number AbsolutSubtraction(const Number& num);
  Number Gcd(const Number& num) const;
  bool IsSqrt() const;

};

inline bool Number::IsPrime() const {
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

inline bool Number::IsPrimeStartMiddle() const {
  Number it(intSqrt()++), tmp;
  bool result = true;
  for (; it >= 2; it--) {
    tmp = *this % it;
    if (tmp == kZero) {
      result = false;
      break;
    }
  }

  return result;
}

inline void Number::NextPrime() {
  this->operator++();
  for (; !this->IsPrime();this->operator++());
}

inline bool Number::IsRelativelyPrime(const Number &num) {
  Number greater_num = *this < num ? num: *this;
  Number less_num = *this < num ? *this: num;
  Number limit_num = less_num / kTwo;
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

  if (greater_num % less_num == 0) {
    result = false;
  }

  return result;
}

inline Number Number::AbsolutSubtraction(const Number &num) {
  return *this > num ? *this - num: num - *this;
}

inline Number Number::Gcd(const Number &num) const {
  Number remainder, this_value(*this), num_value(num), zero(0);
  while (num_value != zero) {
    remainder = this_value % num_value;
    this_value = num_value;
    num_value = remainder;
  }
  return this_value;
}

inline bool Number::IsSqrt() const {
  return intSqrt() * intSqrt() == *this ? true : false;
}

#endif  // NUMBER_H_

