/**
  * @name factoring_method.h
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#ifndef FACTORING_METHOD
#define FACTORING_METHOD
#include "rsa_data.h"

class FactoringMethod : public RsaData  {
 public:
  virtual void Factoring() = 0;
};

#endif  // FACTORING_METHOD
