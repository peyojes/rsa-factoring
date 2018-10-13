#ifndef FACTORING_METHOD_INTERFACE_H
#define FACTORING_METHOD_INTERFACE_H
#include "rsa_data.h"

class FactoringMethodInterface: public RsaData {
  FactoringMethodInterface() = delete;
  virtual void Factoring() = 0;
  void SetPublicKey(const Number& public_key);
};

void FactoringMethodInterface::SetPublicKey(const Number &public_key) {
  public_key_ = public_key;
}

#endif  // FACTORING_METHOD_INTERFACE_H
