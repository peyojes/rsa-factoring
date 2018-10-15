#ifndef FACTORING_METHOD_INTERFACE_H
#define FACTORING_METHOD_INTERFACE_H
#include "rsa_data.h"

class FactoringMethodInterface {
 public:
  virtual void Factoring() = 0;
};

#endif  // FACTORING_METHOD_INTERFACE_H
