#include <gtest/gtest.h>

#include "../include/simple_rsa_factoring.h"

TEST(SimpleRsaFactoringStartingFromBeginning, emptyInitialization) {
  SimpleRsaFactoringStartingFromBeginning factoring;
  EXPECT_EQ(0, factoring.GetModulus().toInt());
}

TEST(SimpleRsaFactoringStartingFromBeginning, factoring) {
  SimpleRsaFactoringStartingFromBeginning simp_factor;
  simp_factor.SetModulus(33);
  simp_factor.SetPublicKey(7);
  simp_factor.Factoring();
  int  p(simp_factor.GetP().toInt());
  int  q(simp_factor.GetQ().toInt());
  bool result = false;
  if ((p == 3 && q == 11) ||(p == 11 && q == 3)) {
    result = true;
  }

  EXPECT_TRUE(result);
  EXPECT_EQ(20, simp_factor.GetValueOfEulerFunction().toInt());
  EXPECT_EQ(3, simp_factor.GetPrivateKey().toInt());
  EXPECT_EQ(7, simp_factor.GetPublicKey().toInt());
}
TEST(SimpleRsaFactoringStartingFromBeginning, moreComplicatedFactoring) {
  SimpleRsaFactoringStartingFromBeginning simp_factor;
  simp_factor.SetModulus(143);
  simp_factor.SetPublicKey(17);
  simp_factor.Factoring();
  int  p(simp_factor.GetP().toInt());
  int  q(simp_factor.GetQ().toInt());
  bool result = false;
  if ((p == 11 && q == 13) ||(p == 11 && q == 13)) {
    result = true;
  }

  EXPECT_TRUE(result);
  EXPECT_EQ(120, simp_factor.GetValueOfEulerFunction().toInt());
  EXPECT_EQ(113, simp_factor.GetPrivateKey().toInt());
  EXPECT_EQ(17, simp_factor.GetPublicKey().toInt());
}

TEST(SimpleRsaFactoringStartingFromMiddle, factoring) {
  SimpleRsaFactoringStartingFromMiddle simp_factor;
  simp_factor.SetModulus(143);
  simp_factor.SetPublicKey(17);
  simp_factor.Factoring();
  int  p(simp_factor.GetP().toInt());
  int  q(simp_factor.GetQ().toInt());
  bool result = false;
  if ((p == 11 && q == 13) ||(p == 11 && q == 13)) {
    result = true;
  }

  EXPECT_TRUE(result);
  EXPECT_EQ(120, simp_factor.GetValueOfEulerFunction().toInt());
  EXPECT_EQ(113, simp_factor.GetPrivateKey().toInt());
  EXPECT_EQ(17, simp_factor.GetPublicKey().toInt());
}
