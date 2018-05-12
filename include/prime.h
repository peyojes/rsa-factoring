#include <string>
#include <iostream>

#include "gmpxx.h"

class Prime : public mpz_class {
 public:
  Prime() : mpz_class() {}
  Prime(const int number): mpz_class(number) {}
  Prime(const std::string &number) : mpz_class(number) {}

//  Prime EulerFunction(const int q) {
//    Prime result(q);
//    result--;
//    std::cout << result << std::endl;
//    result = result * this;
//    return result;
//  }

};
