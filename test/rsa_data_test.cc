#include <gtest/gtest.h>

#include "../include/rsa_data.h"

TEST(RsaData, emptyInitialization) {
  RsaData data;
  EXPECT_EQ(data.GetP(), 0);
  EXPECT_EQ(data.GetQ(), 0);
  EXPECT_EQ(data.GetPrivateKey(), 0);
  EXPECT_EQ(data.GetPublicKey(), 0);
  EXPECT_EQ(data.GetValueOfEulerFunction(), 0);
  EXPECT_EQ(data.GetModulus(), 0);
}

TEST(RsaData, initializationWithPAndQ) {
  RsaData data(7, 11);
  EXPECT_EQ(data.GetP(), 7);
  EXPECT_EQ(data.GetQ(), 11);
  EXPECT_EQ(data.GetPrivateKey(), 13);
  EXPECT_EQ(data.GetPublicKey(), 37);
  EXPECT_EQ(data.GetValueOfEulerFunction(), 60);
  EXPECT_EQ(data.GetModulus(), 77);
}

TEST(RsaData, SetModulus) {
  RsaData data;
  data.SetModulus(30);
  EXPECT_EQ(data.GetModulus(), 30);
}
