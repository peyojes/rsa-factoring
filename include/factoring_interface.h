#ifndef FACTORING_INTERFACE_HPP
#define FACTORING_INTERFACE_HPP
#include "rsa_data.h"

class FactoringInterface: public RsaData {
  FactoringInterface() = delete;
  virtual void Factoring() = 0;
  void SetPublicKey(const Number& public_key);
};

void FactoringInterface::SetPublicKey(const Number &public_key) {
  public_key_ = public_key;
}

#endif  // FACTORING_INTERFACE_HPP
