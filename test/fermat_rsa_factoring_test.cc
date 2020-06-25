/**
  * @name fermat_rsa_factoring_test.cc
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#include <gtest/gtest.h>
#include "../include/fermat_rsa_factoring.h"

TEST(FermatRsaFactoring, emptyInitialization) {
  FermatRsaFactoring factor;
  EXPECT_EQ(0, factor.GetModulus().toInt());
}

TEST(FermatRsaFactoring, factoring) {
  FermatRsaFactoring factoring;
  factoring.SetModulus(5959);
  factoring.SetPublicKey(777);
  factoring.Factoring();
  int  p(factoring.GetP().toInt());
  int  q(factoring.GetQ().toInt());
  bool result = false;
  if ((p == 59 && q == 101) ||(p == 101 && q == 59)) {
    result = true;
  }

  EXPECT_TRUE(result);
  EXPECT_EQ(5800, factoring.GetValueOfEulerFunction().toInt());
  EXPECT_EQ(777, factoring.GetPublicKey().toInt());
}
