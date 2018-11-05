#ifndef FACTORING_METHOD
#define FACTORING_METHOD
#include "rsa_data.h"

class FactoringMethod : public RsaData  {
 public:
  virtual void Factoring() = 0;
};

#endif  // FACTORING_METHOD
