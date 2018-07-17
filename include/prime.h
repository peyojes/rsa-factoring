#include <string>
#include <iostream>

#include "InfInt.h"

class Prime : public InfInt {
 public:
  Prime() : InfInt() {}
  Prime(const int number): InfInt(number) {}
  Prime(const std::string &number) : InfInt(number) {}

  const Prime& EulerFunction(const Prime &q);
  const Prime& EulerFunction(const int q);
  const Prime& EulerFunction(const std::string& q);

};

const Prime& Prime::EulerFunction(const Prime& q) {
  Prime local(q);
  local--;
  operator --();
  *this *= local;
  return *this;
}

const Prime& Prime::EulerFunction(const int q) {
  Prime local(q);
  return EulerFunction(local);
}

const Prime &Prime::EulerFunction(const std::string &q) {
  Prime local(q);
  return EulerFunction(local);
}
