/**
  * @name pollard_rsa_factoring_test.cc
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#include <gtest/gtest.h>
#include "../include/pollard_rsa_factoring.h"

TEST(RhoPollandaFactoring, emptyInitialization) {
  PollardRsaFactoring factor;
  EXPECT_EQ(0, factor.GetModulus().toInt());
}

TEST(RhoPollandaFactoring, factoring) {
  PollardRsaFactoring factoring;
  factoring.SetModulus(143);
  factoring.SetPublicKey(17);
  factoring.Factoring();
  int  p(factoring.GetP().toInt());
  int  q(factoring.GetQ().toInt());
  bool result = false;
  if ((p == 11 && q == 13) ||(p == 11 && q == 13)) {
    result = true;
  }

  EXPECT_TRUE(result);
  EXPECT_EQ(120, factoring.GetValueOfEulerFunction().toInt());
  EXPECT_EQ(17, factoring.GetPublicKey().toInt());
}
