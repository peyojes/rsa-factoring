#ifndef METHOD_FACTORING_INTERFACE_H
#define METHOD_FACTORING_INTERFACE_H
#include "rsa_data.h"

class MethodFactoringInterface: public RsaData {
  MethodFactoringInterface() = delete;
  virtual void Factoring() = 0;
  void SetPublicKey(const Number& public_key);
};

void MethodFactoringInterface::SetPublicKey(const Number &public_key) {
  public_key_ = public_key;
}

#endif  // METHOD_FACTORING_INTERFACE_H
