#include <gtest/gtest.h>
#include "../include/prime.h"

TEST(initial, empty) {
  Prime prime;
  EXPECT_EQ(0,prime.toInt());
}

TEST(initial, integer) {
  Prime prime(1);
  EXPECT_EQ(1,prime.toInt());
}

TEST(initial, string) {
  Prime prime("0");
  EXPECT_EQ(0, prime.toInt());
}

TEST(multiplication, integer) {
  Prime prime(2);
  prime *= 2;
  EXPECT_EQ(4, prime.toInt());
}

TEST(multiplication, Prime) {
  Prime prime(2);
  prime *= prime;
  EXPECT_EQ(4, prime.toInt());
}

TEST(EulerFunction, Prime) {
  Prime prime(3), four_tmp(4);
  prime.EulerFunction(four_tmp);
  EXPECT_EQ(6, prime.toInt());
}

TEST(EulerFunction, integer) {
  Prime prime(3);
  prime.EulerFunction(4);
  EXPECT_EQ(6, prime.toInt());
}

TEST(EulerFunction, string) {
  Prime prime(3);
  Prime local = prime;
  prime.EulerFunction("4");
  EXPECT_EQ(6, prime.toInt());
  EXPECT_EQ(3, local.toInt());
}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
