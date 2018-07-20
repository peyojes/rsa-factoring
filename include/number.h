#ifndef NUMBER_H_
#define NUMBER_H_

#include <string>

#include "InfInt.h"

class Number : public InfInt {
 public:
  Number(): InfInt() {}
  Number(const int number): InfInt(number) {}
  Number(const char* number): InfInt(number) {}
  Number(const std::string& number): InfInt(number) {}
  Number(const InfInt& number): InfInt(number) {}

  bool IsPrime();
};

bool Number::IsPrime() {
  Number it(2), tmp;
  bool result = true;
  for (; it < this->operator /( it); it++ ) {
    tmp = this->operator%( it);
    if (tmp == 0) {
      result = false;
      break;
    }
  }

  return result;
}

#endif //  NUMBER_H_
