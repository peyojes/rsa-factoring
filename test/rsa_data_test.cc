/**
  * @name rsa_data_test.cc
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
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

TEST(RsaData, SetPublicKey) {
  RsaData data;
  data.SetPublicKey(30);
  EXPECT_EQ(30, data.GetPublicKey().toInt());
}
