#include <gtest/gtest.h>

#include "../include/wisniewski_rsa_factoring.h"

TEST(WisniewskiRsaFactoring, emptyInitialization) {
  WisniewskiRsaFactoring factoring;
  EXPECT_EQ(0,factoring.GetModulus().toInt());
}

TEST(WisniewskiRsaFactoring, factoring) {
  WisniewskiRsaFactoring factoring;
  factoring.SetModulus(143);
  factoring.SetPublicKey(17);
  factoring.Factoring();
  int  p(factoring.GetP().toInt());
  int  q(factoring.GetQ().toInt());
  bool result = false;
  if ((p == 13 && q == 11) ||(p == 11 && q == 13)) {
    result = true;
  }

  EXPECT_TRUE(result);
  EXPECT_EQ(120, factoring.GetValueOfEulerFunction().toInt());
  EXPECT_EQ(113, factoring.GetPrivateKey().toInt());
  EXPECT_EQ(17, factoring.GetPublicKey().toInt());
}
