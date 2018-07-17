#include <string>
#include <iostream>

#include "InfInt.h"

class Prime : public InfInt {
 public:
  Prime() : InfInt() {}
  Prime(const int number): InfInt(number) {}
  Prime(const std::string &number) : InfInt(number) {}

//  Prime EulerFunction(const int q) {
//    Prime result(q);
//    result--;
//    std::cout << result << std::endl;
//    result = result * this;
//    return result;
//  }

};
